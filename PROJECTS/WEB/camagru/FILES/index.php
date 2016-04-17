<?php
session_start();
include_once('config/header.php');
?>

<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>Camagru</title>
		<link rel="stylesheet" type="text/css" href="css/main.css" />
	</head>
	<body>
		<header>
			<a href="index.php">Index</a>
			<a href="index.php?page=gallery">Gallery</a>
			<?php
				if (isset($_SESSION['user_id']))
					echo "<a href='logout.php'>Logout</a>";
				else
					echo "<a href='login.php'>Login</a>";
			?>
			<a href="index.php?page=account">My Account</a>
		</header>
<?php
if (isset($_SESSION['user_id']) && $_GET['page'] != 'gallery') {
	if ($_GET['page'] == 'account')
		include_once('account.php');
	else {
?>
		<section>
			TEST
		</section>
<?php
	}
} else if ($_GET['page'] == 'gallery') {
	include_once('gallery.php');
}
?>
		<footer>
		</footer>
	</body>
</html>
