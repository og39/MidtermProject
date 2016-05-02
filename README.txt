README

To start:

user.sql will create the database and mysql account that accesses it.

Workoutsdump.sql will create the tables and data.

use file 'userinterface.php'
 
the format for commands is:

userinterface.php -u <user id> -p <password> -c <command arguements...>


Available Commands:

1. 'addUser'

    ***Only trainers can create new users ***

    userinterface.php -u <user id> -p <password> -c addUser <new user id> <first name> <last name> <phone number> <account type> <new password>
  
    Phone number format:########## (only digits)
    Account Type is either 'user' or 'trainer' (lowercase)

2. 'updatePassword'

    userinterface.php -u <user id> -p <old password> -c updatePassword <new password>

3. 'createRoutine'

    ***Only trainers can create routines ***
  
    userinterface.php -u <user id> -p <password> -c createRoutine <routine name>

4.  'deleteRoutine'
    
    ***Only trainers can delete routines ***
  
    userinterface.php -u <user id> -p <password> -c deleteRoutine <routine name>

5. 'trainerReport

    ***Only trainers can view this report ***
  
    userinterface.php -u <user id> -p <password> -c trainerReport <routine name>
    
6. 'progressReport'
  
    userinterface.php -u <user id> -p <password> -c progressReport <routine name> 

7. 'assignRoutine'
   
    userinterface.php -u <user id> -p <password> -c assignRoutine <user name> <rID>
    
    User Name is the person you are assigning a routine to.
    
    Routine ID(rID) is the number you add when entering new sets.

8. 'designRoutine'
   
    userinterface.php -u <user id> -p <password> -c designRoutines <rouintine ID> <routine name> <routine description>	

   Routine ID  is thte ID given to the new routine.
   
   Routine name if the name you are giving the new routine.

   Routine Description details the routine.

9. 'myRoutines'

    userinterface.php -u <user id> -p <password> -c myRoutines 

    Will print out what routines you are assigned to.

10. 'addSet'
  
    userinterface.php -u <user id> -p <password> -c addSet <routine name> <date> <Exercise> <Set Number> <Weight> <Reps> <Body Part> <rID>
    
    Date format: YYYY-MM-DD
    
  
