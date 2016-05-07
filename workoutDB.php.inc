<?php

class workoutFunc
{
   private $db;
   private $ini;
 	
   public function __construct($inifile)
   {
	
	$this->ini = parse_ini_file($inifile,true);
	$host = $this->ini['workoutDB']['host'];
	$user = $this->ini['workoutDB']['user'];
	$password = $this->ini['workoutDB']['password'];
	$database = $this->ini['workoutDB']['database'];
	$this->db = new mysqli($host,$user,$password,$database);
	
	if ($this->db->connect_errno > 0)
	{
		echo __FILE__.":".__LINE__.": failed to connect to db, re: ".$this->db->connect_error.PHP_EOL;
		exit(0);
	}
   }

   public function __destruct()
   {
	$this->db->close();
   }

   public function createRoutine ($userID, $passwd, $routineName)
   {

      $routineName = $this->db->real_escape_string($routineName);
      $query= "create table $routineName(
	      CurDate date,
	      Exercise varchar(20),
	      SetNum int(2),
	      Weight int(3),
	      Reps int(2),
	      BodyPart varchar(10),
	      userID varchar(10),
	      rID varchar(10),	
	      primary key (CurDate,Exercise,SetNum,userID),
	      foreign key (userID) references Users(userID));";
    
    $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
	echo "Routine Created".PHP_EOL;
   }

   public function deleteRoutine ($userID,$passwd,$routineName)
   {
      
      $routineName = $this->db->real_escape_string($routineName);
      $query = "drop table $routineName;";
      $results = $this->db->query($query);
	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
	echo "Routine Deleted".PHP_EOL;
   }
   
   public function trainerReport($userID,$passwd,$routineName)
   {

     $routineName = $this->db->real_escape_string($routineName);
     $query = "select * from $routineName order by userID, CurDate, Exercise, SetNum;";	     	
     $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
     	while ($row = $results->fetch_assoc())
	{ 
	    echo $row['userID']." ".$row['CurDate']." ".$row['Exercise']." ".$row['SetNum']." ".$row['Weight']." ".$row['Reps']." ".$row['BodyPart'].PHP_EOL;	
	}
   }	   

  public function addSet($userID,$passwd,$routineName,$date,$exercise,$set,$weight,$reps,$bodypart,$rID)
  {
      
      $userID = $this->db->real_escape_string($userID);
      $date = $this->db->real_escape_string($date);
      $exercise = $this->db->real_escape_string($exercise);
      $set = $this->db->real_escape_string($set);
      $reps = $this->db->real_escape_string($reps);
      $weight = $this->db->real_escape_string($weight);
      $bodypart = $this->db->real_escape_string($bodypart);
      $routineName = $this->db->real_escape_string($routineName);
      $rID = $this->db->real_escape_string($rID);	
      
      $query = "insert into $routineName (CurDate,Exercise,SetNum,Weight,Reps,BodyPart,userID,rID) values ('$date','$exercise',$set,$weight, 	$reps,'$bodypart','$userID','$rID');";
      $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
	echo "Set added".PHP_EOL;
  }
  
  public function progressReport($userID,$passwd,$routineName)
  {
      
      $userID = $this->db->real_escape_string($userID);
      $routineName = $this->db->real_escape_string($routineName);
      
      $query = "select * from $routineName where userID = '$userID'
		order by CurDate, Exercise, SetNum;";
     $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
     	while ($row = $results->fetch_assoc())
	{ 
	    echo $row['CurDate']." ".$row['Exercise']." ".$row['SetNum']." ".$row['Weight']." ".$row['Reps']." ".$row['BodyPart']." ".$row['userID'].PHP_EOL;	
	}
  }
  
  public function assignRoutine($userID,$passwd,$username,$rID)
  {
      $userID = $this->db->real_escape_string($userID);
      $username = $this->db->real_escape_string($username);
      $rID = $this->db->real_escape_string($rID);
      
      $query = "insert into assigndRT (userID,rID) values ('$username','$rID');";
      $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}

	echo "Routine assigned".PHP_EOL;      
  }
  
  public function designRoutine($userID,$passwd,$rID,$routineName,$routineDesc)
  {
      $userID = $this->db->real_escape_string($userID);
      $rID = $this->db->real_escape_string($rID);
      $routineName = $this->db->real_escape_string($routineName);
      $routineDesc = $this->db->real_escape_string($routineDesc);
      
      $query = "insert into routineDesc (rID, Routine_Name, Routine_Desc ) values ('$rID','$routineName','$routineDesc');";
      $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}

	echo "Routine designed".PHP_EOL;      
  }  

  public function myRoutines($userID, $passwd)
  {
      $userID = $this->db->real_escape_string($userID);
            $query = "select * from assigndRT as a join routineDesc as r on a.rID = r.rID where userID = '$userID'";
     $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
     	while ($row = $results->fetch_assoc())
	{ 
	    echo $row['Routine_Name']." ".$row['rID']." ".$row['Routine_Desc'].PHP_EOL;	
	}
  }

  public function exportUsers($userID, $passwd)
  {
    $userID = $this->db->real_escape_string($userID);
    
    $json_data=array();
    $query = "select * from Users"; 
    $results = $this->db->query($query);
    	if ($this->db->errno > 0)
	{
	    echo __FILE__.":".__LINE__."DB error: ".$this->db->error.PHP_EOL;
	}
    $index=0;
    while ($row =$results->fetch_assoc())
    {
      $json_data[$index]=$row;
      $index++;
    }
    echo json_encode($json_data).PHP_EOL;
    $fp = fopen('Users.json','w');
    fwrite($fp, json_encode($json_data));
    fclose($fp);
   
   exec("mongoimport -h ds015892.mlab.com:15892 -d it635 -c Users -u it635 -p boom --jsonArray --file Users.json");
    	
  }
}


?>
