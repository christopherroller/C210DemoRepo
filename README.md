# C210DemoRepo




The intent of this project was to encapsulate a banking application to allow the user to experiment with various saving techniques and 
calculate their return based on changing savings percentages, initial principal and length of time. 

This project serves as a good example of properly splitting out header files from source files to make the code much more readable and
maintainable. The main method is all of 30 lines and properly implements class based and method based architecture that is inherent in OOP. 
Everything related to an Account is properly encapsulated in the account class. The main method simply acts as a control. This makes the
application much more efficient and if the user wanted to implement a different type of Account, they could, quickly and securely.

I didn't find any particular piece of code challenging on this assignment, however I did find some of the actual logic challenging,
in trying to figure out how appropriately to architect and capture everything I needed to track for the user account. It just took me a
couple iterations of stepping through the code to make sure I had everything correct.

The use of appropriate header and source files for a clean project is something I'll use on basically every other C++ project I write.
It makes the code much more maintainable, and rather than looking through bloated cpp files I can just update a header file and then
do a build, and as soon as an error pops up I know what I need to update in my cpp file. This was far and above the largest aspect of making
my code maintainalbe and readable. As far as adaptability, using an Account object that was defined in my Account.h file, If I wanted
to implement another Account type, I could simply create another "Account" object, say a "CheckingAccount.cpp" that uses the Account.h header
file but implements the methods in a different manner. The header file just acts as a template and tells the user what kinds of parameters
and methods it needs, but beyond that it's up to the source file to fill in the method bodies.


