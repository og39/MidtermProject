drop database if exists Workouts;
create database Workouts;
create user 'WorkoutAdmin'@'localhost' identified by "midterm";
grant all privileges on Workouts.* to 'WorkoutAdmin'@'localhost';
flush privileges;
