<?php 
// Database connection
$servername = "localhost";
$username = "root"; // Your MySQL username
$password = ""; // Your MySQL password
$dbname = "roombooking"; // Your database name

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Room booking form handling
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['submit_enquiry'])) {
    // Sanitize input data
    $name = mysqli_real_escape_string($conn, $_POST['Name']);
    $email = mysqli_real_escape_string($conn, $_POST['Email']);
    $contactNo = mysqli_real_escape_string($conn, $_POST['Contact_No']);
    $enquiry = mysqli_real_escape_string($conn, $_POST['Enquiry']);

    // Insert enquiry data into database
    $sql = "INSERT INTO enquiry (Name, Email, Contact_No, Enquiry) 
            VALUES ('$name', '$email', '$contactNo', '$enquiry')";

    if ($conn->query($sql) === TRUE) {
        echo "Enquiry successful!";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

// Close database connection
$conn->close();
?>