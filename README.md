Solution to Oracle MDC - Coding Challenge.

The original problem statement is:

Given a list of movie names, overlap different movie names to generate the longest string you can. In order to include a movie name, the first words of it have to match the last words of another movie name. Each movie name can be used once at most.

For example, if you have the following list of movie names:

- How to Train your Dragon.
- Gods and Monsters.
- Dragon Ball Z: Battle of the Gods.
- Monsters vs Aliens.
- 8 Mile.

Then a possible resulting string would be:

How to Train your Dragon Ball Z: Battle of the Gods and Monsters vs Aliens

Also is allowed partial overlap as the following example:

sentence 1: aaa bbb ccc    
sentence 2: bbb ccc ddd eee

aaa bbb ccc ddd eee is a valid output

With the code shown above. I got a valid solution of 14182 characters lenght. However this is not the most optimal solution. You can try by yourself to optimize code and get a better solution. This code is running in less than a second and some of the elements used to solve the problem were:

-  Graph.
- Memorization.
- Recursion.

Also is included the input file for testing. 

If you want to learn more about the problem go to: https://apex.oracle.com/pls/apex/f?p=MDC_MOVIE%3A1
