<?php
$host = "localhost";
$db = "iot_lab";
$user = "iot_user";
$pass = "iot@1122";
$con = mysqli_connect($host,$user,$pass,$db);
$query = "select * from DHT_sensor";
$result = mysqli_query($con,$query);
$count = mysqli_num_rows($result);
echo $count;
echo "<br>";
while($row = mysqli_fetch_array($result)){
	echo $row[3];
	echo "<br>";}
?>