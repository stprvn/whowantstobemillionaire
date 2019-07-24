# Who Wants To be a Millionaire
##                                                                                Final project - Fundamental of Programming Course 
######                                                                            Language   : C++
######                                                                            Input Type : Keyboard

---

WWTBM (Who wants to be millionaire) is a trivia games where prizes given in every single question that player can answer. 
There will be 3 Lifelines : 
1. 50-50 : the game's computer eliminates two wrong answers from the current question, leaving behind the correct answer and one incorrect answer.

2. Call friend : the contestant is connected with a friend over a phone line and is given 30 seconds to read the question and answers and solicit assistance.

3. Audience : the audience takes voting pads attached to their seats and votes for the answer that they believe is correct. The computer tallies the results and displays them as percentages to the contestant.
    

### How it works


###### Compile :                       *g++*   *whowantstobemillionaire.cpp*  *-o*   *[name]*
There are some packages of question save as file external (extention .txt) that will be randomly choosen by the main program
and a highscore file that contains name and score of players who ever played.
Player will ask to fill up name bar, and then continue to start the game. 
The player will answer each question with choices a, b, c, d or x for the lifeline and o to give up
if the player gives up, the number of prizes obtained is the number of the last prize that was successfully answered
The game ends when the player answers with the wrong answer or all questions are successfully completed
The player who answers incorrectly will get a prize based on the checkpoint obtained.
