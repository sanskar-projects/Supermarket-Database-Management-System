<! DOCTYPE html>
<html>
<head>

<link rel="stylesheet" href="pysda.css">

<meta name="viewport" content="width=device-width,initial-scale=1.0">

</head>

<body>

<p class="home">
<a href="index.html">
go to home
</a>
</p>
<br>
  <br>
  <br>
  <br>
  <br>
<p>
SUPERMARKET DATABASE MANGEMENT SYSTEM
</p>

<br>
<br>
<br>
<br>
<br>

<hr>

<p>
Mission of the project
</p>

<p>
A program written in C language intended to function as a database management system for supermarkets.<br>
It doesn't require an interaction with any RDBMS software but still capable of synchronizing data by utiizing files as databases.<br>
Being written in a low level language which is closer to machine code it has a very fast performance and minimal execution time.<br>
It utilizes 3 files for it's proper execution namely database.txt, invoice.txt and cache.txt which are generated automatically when for the first time backup or synchronization is performed.<br>
database.txt file stores the SN, ID, name, MRP, discount and quantity of all the products.<br>
invoice.txt file stores all the invoices generated.<br>
cache.txt stores an integer which indicates the number of products existing in the database.txt file.<br>
For adding a certain product the user is asked to enter it's ID, name, MRP, discount and quantity.<br>
Products are displayed with their corresponding SN, ID, name, MRP, SP, discount and quantity where SN and SP are generated automatically from discount and MRP (SP=MRP-MRP*discount*0.01)<br>
For generating an invoice the user is asked to select a certain product by it's SN then enter the quantity.<br>
The users can continue adding products to the invoice as long as the they want then they are asked to enter the customer's contact number and the invoice is generated.<br>
The generated invoice contains customer's contact number, date and time, SN, ID, name, MRP, discount, quantity, amount and total amount calculated.<br>
The quantity of a certain product in the database is reduced according to it's quantity added in the invoice.<br>
For removing a certain product the user is asked to select it by entering it's SN.<br>
An option is provided to synchronize the data with the database which first backs up data to the database then loads data from the database consecutively.<br>
<br>NOTE: It's recommended to synchronize the data after removing a certain product and before removing another product otherwise undesired changes may be reflected in the data.
</p>

<hr>
<hr>

<br>
<br>
<br>
<br>
<br>

<p>
LOADING DATA FROM THE DATABASE
</p>
<hr>
<img src="load.png" id="1">

<hr>

<p>
ADDING PRODUCTS
</p>
<hr>
<img src="add.png" id="2">

<hr>

<p>
DISPLAYING PRODUCTS
</p>
<hr>
<img src="display.png" id="3">

<hr>

<p>
GENERATING INVOICE
</p>
<hr>
<img src="bill.png" id="4">

<hr>

<p>
data has been backed up to the database.txt file
</p>
<hr>
<img src="db.png" id="5">

<hr>

<p>
REMOVING A PRODUCT
</p>
<hr>
<img src="pop.png" id="6">

<hr>

<p>
SYNCHRONIZING DATA WITH THE DATABASE
</p>
<hr>
<img src="sync.png" id="7">

<hr>

<p>
generated invoices have been backed up to the invoice.txt file
</p>
<hr>
<img src="invoice.png" id="8">

<hr>

<p>
an integer has been typed on the cache.txt file which indicates the number of products existing in the database.txt file
</p>
<hr>
<img src="cache.png" id="9">

</body>
