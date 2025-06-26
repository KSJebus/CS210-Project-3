# CS210-Project-3 

## Summarize the project and what problem it was solving. 
This program helps to analyze grocery items by reading data, purchases, from a text file and allowing the user to view item frequencies in different formats. The user can search for a single item’s count, view all items numerically, or see all items frequency in a histogram representation. 

## What did you do particularly well? 
I find that what I did well was being able to think through what I needed my program to do; making it run, have clean code, and being functional in the future 

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on? 
One thing that I could make improvements on is creating separate files for functions. Because I have all my functions in one file, it could make the code harder to read and makes it unorganized. If I made separate files, I would have made one for the “front end” of the program, the display and functionality functions and the other would be for the “back end” functions; specificItem, allItemsNumerically, and allItemsHistogram  

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network? 
The pieces of code that I found to be difficult was deciding on what type of container to use to store the data from the input file and the validMenuOption function. For the container to use, I started off using a set to keep track of all unique names in the input file but was finding it difficult to link the set to search the input file. So, I reread the guidelines for the project and noticed it recommended using a map. When I looked up maps in zyBooks, I noticed that I would be able to do what I was trying to do within the map instead of creating a new function. For the validMenuOption, I used a try-catch method and because I don’t have much practice with it, it took more time and double checking to make sure I used it properly 

## What skills from this project will be particularly transferable to other projects or course work? 
Some skills I learned from this project that would be particularly transferable to other projects are the ability to organize input data and be able to output the data in a more concise and readable form. 

## How did you make this program maintainable, readable, and adaptable?
I made my program more maintainable, readable, and adaptable by naming my functions with clear names to understand what each function is doing, adding comments to let the user know what the code underneath is doing, and rereading the input file to make sure the data the code is reading is up to date. 
