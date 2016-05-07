drop database if exists Workouts2;
create database Workouts2;
create user 'Admin'@'localhost' identified by "final";
grant all privileges on Workouts2.* to 'Admin'@'localhost';
flush privileges;
