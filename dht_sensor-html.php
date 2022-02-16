<html>
<title>My DHT Sensor Data</title>
<center>
<h1> My Sensor Data </h1>
<table border = "3" width="50%">
<head>
<meta http-equiv = "refresh" content="5">
</head>
<tr>
<th>Id</th>
<th>Date</th>
<th>Time</th>
<th>Temperature</th>
<th>Humidity</th>
</tr>

<?php
$host = "localhost";
$db = "iot_lab";
$user = "iot_user";
$pass = "iot@1122";
$con = mysqli_connect($host,$user,$pass,$db);
$query = "select * from DHT_sensor order by id Desc"; // 
$result = mysqli_query($con,$query);
$count = mysqli_num_rows($result);
//echo $count;
//echo "<br>";
while($row = mysqli_fetch_array($result)){
	echo "<tr>";
	echo "<td>".$row['id']."</td>";
	echo "<td>".$row['date']."</td>";
	echo "<td>".$row['time']."</td>";
	echo "<td>".$row['humidity']."</td>";
	echo "<td>".$row['temperature']."</td>";
	echo "</tr>";
}
?>

     </table>
</center>
</html>