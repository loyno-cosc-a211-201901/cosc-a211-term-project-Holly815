
//preprocessor
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//global variables
int batteryLife, batteries, event, firstAidKit, userAction; 
int runaway, campItem, eventNum, pocketKnife, wolfeChoice, flashlight, userActionTwo;

//prototype functions
int knife();
int randomEvent();
int randomEventTwo();
int randomEventThree();
int triggerTrap();
int userChose();
int batteryLifeRemaining();
int outOfBattery();
int endgame();
int wolfe();
int wolfeRun();
int wolfeFight();

//game over
int endgame(){
    //if player dies
    cout << "Game Over." << endl;
    exit(0);
    return 0;
}

//out of battery life function
int outOfBattery(){
    if (batteryLife == 0){
        //battery runs out
        cout << "Your flashlight briefly flickers, then doesn't turn on again. The battery is dead." << endl;
        if (batteries > 0){
            //reload flashlight if possible
            batteries--;
            cout << "You put a new battery in the flashlight. You have " << batteries << " remaining." << endl;
            batteryLife = 100;
            flashlight = 1;
        }
        else if (batteries == 0){
            //if no more batteries
            cout << "You don't have any more batteries to put in the flashlight. Be careful!" << endl;
            flashlight = 0;
        }
    }
    return 0;
}

//check battery function
int batteryLifeRemaining(){
    //display remaining battery life after using light
    cout << "There is now " << batteryLife << "% battery life left, and " << batteries << " batteries remaining." << endl;
    outOfBattery();
    return 0;
}

//ask for user action function
int userChose(){ 
    //options
    cout << "1. Investigate with the flashlight" << endl;
    cout << "2. Investigate without the flashlight" << endl;
    cout << "3. Ignore it and keep searching" << endl;

    cin >> userAction;
    cout << endl;

    while (userAction <= 0 || userAction > 3){ 
        //validate input
        cout << "Please choose a valid action." << endl;
        cin >> userAction;
        cout << endl;
    }

    if (userAction > 0 && userAction < 4) {
        if (userAction == 1){ 
            //use light
            cout << "You chose to investigate with your flashlight." << endl;
            if(flashlight == 1){
                batteryLife -= 10;
                batteryLifeRemaining();
                userActionTwo = 0;
            }
            else if(flashlight == 0){ 
                //if out of battery
                cout << "Your battery is dead!" << endl;
                cout << "Still investigate?" << endl;
                cout << "1. Investigate anyway" << endl;
                cout << "2. Ignore it and keep going." << endl;
                cin >> userActionTwo;

                while (userActionTwo != 1 && userActionTwo != 2) { 
                    //ask for input again
                    cout << "Please choose a valid action." << endl;
                    cin >> userActionTwo;
                }
            
                if (userActionTwo == 1){ 
                    //investigate with no light
                    cout << "You investigate anyway." << endl;
                }
                if (userActionTwo == 2){ 
                    //dont investigate
                    cout << "You ignore it and keep searching." << endl;
                }
            }
        }
        else if (userAction == 2){ 
            //investigate with no light
            cout << "You chose to investigate without the flashlight." << endl;
        }
        else if (userAction == 3){ 
            //dont investigate
            cout << "You ignore the noise, and keep searching." << endl;
        }
    }
    return 0;
}

//triggered bear trap
int triggerTrap(){
    cout << "Oh no! You stepped right into a bear trap!" << endl;
    cout << endl;

    //use first aid kit if available
    if (firstAidKit == 1){
        cout << "You use your first aid kit to wrap up your ankle as best you can, then disarm the trap and move on." <<endl;
        cout << endl;
        firstAidKit--;
    }

    //if no aid kit
    else if (firstAidKit == 0){
        cout << "If only you'd taken the first aid kit from camp..." << endl;
        cout << "You try your best to free your ankle from the trap." << endl;
        cout << endl;

        //20% chance of death
        int success = (rand() % (5-1+1))+1;
        switch(success){
            case 1:
            case 2:
            case 3:
            case 4:{
                //successful escape
                cout << "You barely manage to get free, then disarm the trap and move on." << endl;
                cout << endl;
                break;
            }
            case 5:{
                //player dies
                cout << "You can't get the trap to loosen, despite your struggles." << endl;
                cout << "The blood loss is making your head spin." << endl;
                cout << "The last thing you hear is someone stomping toward you, before everything goes dark." << endl;
                endgame();
                break;
            }
        }
    }
    return 0;
}

//event randomizer
int randomEvent(){
    //randomize event
    event = (rand() % (3-2+1))+1;
    switch(event){
        case 1:{
            // dead animal
            cout << "You hear something rustle near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                cout << "You found birds picking on a rotting dead squirrel. Gross." << endl;
                cout << endl;
            }
            if (userAction == 2 || userActionTwo == 1){
                cout << "You can barely see, but you definitely smell a rotting animal. Gross." << endl;
                cout << endl;
            }
            if (userAction == 3 || userActionTwo == 2){
                cout << "You smell something rank as you pass, but you don't know what it was." << endl;
                cout << endl;
            }
            break;
        }
        case 2:{
            //bear trap
            cout << "You hear something metal clinking near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                cout << "You found a set bear trap! You're lucky you used your flashlight. You disarm the trap and move on." << endl;
                cout << endl;
            }
            if (userAction == 2){
                triggerTrap();
            }
            if (userAction == 3){
                int trap = (rand() % (2-1+1))+1;
                if (trap == 1){
                    triggerTrap();
                }
                if (trap == 2){
                    cout << "An uneasy feeling comes over you as you pass by..." << endl;
                    cout << endl;
                }
            }
            break;        }
        case 3:{
            //empty beer bottle
            cout << "You hear something clink near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0) {
                cout << "You found some empty beer bottles. They look really old." << endl;
                cout << endl;
            }
            if (userAction == 2){
                cout << "The moonlight just barely reflects off some glass on the ground. Probably some empty bottles." << endl;
                cout << endl;
            }
            if (userAction == 3){
                cout << "Hopefully it wasn't anything important." << endl;
                cout << endl;
            }
            break;
        }
    }
    return 0;
}

//event randomizer part two
int randomEventTwo(){
    //randimize event
    event = (rand() % (3-2+1))+1;
    switch(event){
        case 1:{
            // more blood
            cout << "You think you see something shine near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                cout << "You found a puddle of blood. Who's blood is it?" << endl;
                cout << endl;
            }
            if (userAction == 2 || userActionTwo == 1){
                cout << "You can barely see, but it looks like the blood from before. There's a lot more this time." << endl;
                cout << endl;
            }
            if (userAction == 3 || userActionTwo == 2){
                cout << "You get chills down your spine as you pass, and you have no idea what you saw." << endl;
                cout << endl;
            }
            break;
        }
        case 2:{
            // trap
            cout << "You hear some rustling near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                cout << "You found a set bear trap! You're lucky you used your flashlight. You disarm the trap and move on." << endl;
                cout << endl;
            }
            if (userAction == 2){
                triggerTrap();
            }
            if (userAction == 3){
                int trap = (rand() % (2-1+1))+1;
                if (trap == 1){
                    triggerTrap();
                }
                if (trap == 2){
                    cout << "An uneasy feeling comes over you as you pass by..." << endl;
                    cout << endl;
                }
            }
            break;        }
        case 3:{
            // signs of a scuffle
            cout << "You hear some rustling near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0) {
                cout << "The breeze is blowing a bunch of broken branches, as if there was a fight here." << endl;
                cout << endl;
            }
            if (userAction == 2){
                cout << "It seems like it's just the wind blowing some broken branches here." << endl;
                cout << endl;
            }
            if (userAction == 3){
                cout << "It's probably just the wind." << endl;
                cout << endl;
            }
            break;
        }
    }
    return 0;
}

//knife use
int knife(){
    //33.3% chance knife breaks
    int knifeSuccess = (rand() % (3-2+1))+1;
    switch (knifeSuccess){
        case 1:
        case 2: { 
            //successful use
            cout << "You slash at the wolfe with your blade." << endl;
            cout << "You draw blood from it's muzzle, and it whimpers before running away." << endl;
            cout << endl;
            break;
        }
        case 3: { 
            //knife breaks
            cout << "You slash at the wolfe with your blade." << endl;
            cout << "Your blade gets stuck in the wolfe's matted fur." << endl;
            cout << "You work it free, and the wolfe runs away." << endl;
            cout << "Your blade was terribly bent after the fight, and might not open again." << endl;
            cout << endl;
            pocketKnife = 0;
            break;
        }
    }
    return 0;
}

//run from the wolf
int wolfeRun(){
    //33.3% chance wolf chases
    int success = (rand() % (3-2+1))+1;
        if (success == 1){ 
            //you get away
            cout << "You sprint away, and the wolfe gives up on the chase." << endl;
            cout << endl;
        }
        if (success == 2){ 
            //you get away
            cout << "You sprint away, and the wolfe gives up on the chase." << endl;
            cout << endl;
        }
        if (success == 3){ 
            //it chases anyway
            cout << "You sprint away, but the wolfe doesn't want to let you go!" << endl;
            if (runaway == 1){
                cout << "You feel the wolfe's jaws catch your ankle, and you trip and fall." << endl;
                cout << "The last thing you hear is an ominous howl before everything goes dark." << endl;
                endgame();
            }
            else { 
                //automatic fight
                cout << "You have no choice but to fight it off." << endl;
                cout << endl;
                wolfeFight();
            }
        }
    return 0;
}

//fight the wolf
int wolfeFight(){
    cout << endl;
    if (pocketKnife == 1){ 
        //if the knife works
        cout << "You flip open the blade of the pocketknife." <<endl;
        knife();
    }
    else if (pocketKnife == 0){ 
        //if knife is broken
        cout << "You try to open the pocketknife, but the blade is too bent!" << endl;
        cout << "You turn and run from the wolfe." << endl;
        cout << endl;
        runaway = 1;
        wolfeRun();
    }
    return 0;
}

//wolfe first encounter
int wolfe(){ 
    //wolfe encounter
    //the 'e' in 'wolfe' is intentional. I thought it would be funny :D
    cout << "A wolfe leaps from the brush!" << endl;
    cout << endl;

    //ask user for choice
    cout << "What do you do?" << endl;
    cout << "1. Turn and run" << endl;
    cout << "2. Use the knife" << endl;
    cin >> wolfeChoice;

    //validate input
    while (wolfeChoice != 1 && wolfeChoice != 2){
        cout << "Please enter a valid action." << endl;
        cin >> wolfeChoice;
    }

    if (wolfeChoice == 1){
        //user runs away
        wolfeRun();
    }
    if (wolfeChoice == 2){
        //user fights the wolf
        wolfeFight();
    }

    return 0;
}

//event randomizer part three
int randomEventThree(){
    //randomize the event
    event = (rand() % (3-2+1))+1;
    switch(event){
        case 2:{
            // wolfe
            cout << "You hear a branch break near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                //player used light and attracts wolf
                cout << "Your light reflects off two small glowing orbs in the bushes." << endl;
                cout << "A low growl sounds from in front of you, and you see what looks like fur." << endl;
                wolfe();
                cout << endl;
            }
            if (userAction == 2 || userActionTwo == 1){
                //player doesn't use light and attracts wolf
                wolfe();
                cout << endl;
            }
            if (userAction == 3 || userActionTwo == 2){
                //player keeps walking and doesn't attract wolf
                cout << "You can't help but feel you narrowly avoided something dangerous." << endl;
                cout << endl;
            }
            break;
        }
        case 1:{
            //bear trap
            cout << "You hear something creak near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0){
                //player used flashlight and disables trap
                cout << "You found a set bear trap! You're lucky you used your flashlight. You disarm the trap and move on." << endl;
                cout << endl;
            }
            if (userAction == 2){
                //player pokes around with no light and triggers trap
                triggerTrap();
            }
            if (userAction == 3){
                //player walks past and 1 in 3 chance trap is triggered
                int trap = (rand() % (3-2+1))+1;
                if (trap == 1){
                    //trap is triggered
                    triggerTrap();
                }
                if (trap == 2){
                    //no trap
                    cout << "An uneasy feeling comes over you as you pass by..." << endl;
                    cout << endl;
                }
                if (trap == 3){
                    //no trap
                    cout << "An uneasy feeling comes over you as you pass by..." << endl;
                    cout << endl;
                }
            }
        }
        case 3:{
            // signs of a scuffle
            cout << "You hear some rustling near you. What do you do?" << endl;
            userChose();
            if (userAction == 1 && userActionTwo == 0) {
                //player used light
                cout << "The breeze is blowing a bunch of broken branches, as if there was a fight here." << endl;
                cout << endl;
            }
            if (userAction == 2){
                //player didn't use light
                cout << "It seems like it's just the wind blowing some broken branches here." << endl;
                cout << endl;
            }
            if (userAction == 3){
                //player kept walking
                cout << "It's probably just the wind." << endl;
                cout << endl;
            }
            break;
        }
    }
    return 0;
}

int main(){

    //send time(0) to rrand
    srand(time(0));

    //initialize flashlight
    flashlight = 1;

    //game intro
    cout << "You are camping in the woods with your best friend." << endl;
    cout << "He left to go get water from the nearby stream earlier that afternoon," << endl;
    cout << "but it is now well into the evening and he has yet to return." << endl;
    cout << "With no cell signal to contact your friend, you're left with no choice but to search on foot." << endl;
    cout << endl;

    //tutorial
    cout << "You will be presented with many choices throughout the game." << endl;
    cout << "Each set of choices will be numbered." << endl;
    cout << "Enter the number of your choice, followed by the 'enter' or 'return' key." << endl;
    cout << endl;

    //starting item choice
    cout << "You will carry your cell phone, your flashlight, which has limited battery life, and one item of your choice." << endl;
    cout << "Which do you choose?" << endl;
    cout << "1. Single use first aid kit" << endl;
    cout << "2. Extra battery" << endl;
    cout << "3. Don't take anything." << endl;
    cin >> campItem;
    while (campItem != 1 && campItem != 2 && campItem != 3){
        cout << "Please choose a valid option." << endl;
        cin >> campItem;
    }
    cout << endl;

    //player chose first aid kit
    if (campItem == 1){
        cout << "You chose the first aid kit." << endl;
        cout <<endl;

        //add kit to inventory
        firstAidKit = 1;
        batteries = 0;
    }

    //player chose extra battery
    if (campItem == 2){
        cout << "You chose the extra battery." << endl;
        cout <<endl;

        //add battery to inventory
        batteries = 1;
        firstAidKit = 0;
    }

    //player doesn't take anything
    if (campItem == 3){
        cout << "You chose not to take anything from camp, you fool." << endl;
        cout << endl;
        firstAidKit = 0;
        batteries = 0;
    }

    //initialize battery life
    batteryLife = 100;

    //go to the stream
    cout << "You head in the direction of the stream." << endl;
    randomEvent();
    cout << "You walk a bit further." << endl;
    randomEvent();
    cout << "You're nearly halfway to the stream now." << endl;
    randomEvent();
    cout << "You walk a bit further." << endl;
    randomEvent();
    cout << "You're nearly to the stream." << endl;
    randomEvent();

    //find some blood smears
    cout << endl;
    cout << "Finally, you arrive at the stream." << endl;
    cout << "You think you see something shiny on a nearby tree trunk. Use the flashlight to check it out?" << endl;
    cout << "1. Nah, stick your finger in it." << endl;
    cout << "2. Yes, use the light." << endl;
    int bloodChoice;
    cin >> bloodChoice;

    //validate input
    while (bloodChoice != 1 && bloodChoice != 2) {
        cout << "Please choose a valid option." << endl;
        cin >> bloodChoice;
    }

    cout << endl;
    if (bloodChoice == 1){
        cout << "You feel the shiny spot with your finger. It's pretty wet, and you bring your finger closer to your face." << endl;
        cout << "Oh. That's definitely blood." << endl;
    }
    if (bloodChoice == 2){
        cout << "You shine your flashlight on the tree. That's gotta be blood." << endl;
        batteryLife -= 10;
        batteryLifeRemaining();
    }

    cout << endl;
    cout << "After finding the blood, you decide to investigate the area some more." << endl;

    //investigate the area to find the empty thermos and knife
    cout << endl;
    cout << "You poke around near the stream." << endl;
    randomEventTwo();
    cout << "You slowly follow the stream downhill." << endl;
    randomEventTwo();
    cout << "You keep following the stream." << endl;
    randomEventTwo();
    cout << "You see something reflecting the moonlight off in the distance, and get closer." << endl;
    randomEventTwo();

    //find the thermos and knife
    cout << "You arrive at the shiny object. It's your friend's metal thermos!" << endl;
    cout << "You pick up the thermos to inspect it. It's got new scratches, and a dent that looks bloody." << endl;
    cout << "You look at the spot where you picked the thermos up." << endl;
    cout << "You find your friend's pocketknife, and put it in your pocket." << endl;

    //add knife to inventory
    pocketKnife = 1;

    //find footprints
    cout << "You also find a deep footprint alongside long drag marks in the dirt." << endl;
    cout << "Worried for your friend's safety, you decide to follow the footprints." << endl;

    //follow trail of footprints
    cout << endl;
    randomEventThree();
    cout << "You keep following the footprints, further away from camp." << endl;
    randomEventThree();
    cout << "You're not exactly sure where you are anymore, but you can't give up now." << endl;
    randomEventThree();
    cout << "You're completely lost. All you know is that the camp is somewhere south of you." << endl;
    randomEventThree();

    //first contact with missing friend
    cout << "You feel your phone buzz." << endl;
    cout << endl;
    cout << " > > I N C O M I N G   M E S S A G E < < " << endl;
    cout << endl;
    cout << "You quickly open the notification." << endl;
    cout << "It's from your missing friend! You must be close enough to get a signal!" << endl;
    cout << "The previous messages he sent flood your phone." << endl;
    cout << endl;
    cout << " > 5:55...yo it's getting real dark. i'm heading back now." << endl;
    cout << " > 6:15...i dont think i'm alone out here. come meet me?" << endl;
    cout << " > 6:17...just realized no signal. lemme know when u get this." << endl;
    cout << " > 6:20...theres someone here for sure." << endl;
    cout << " > 6:27...he's chasing me! nicked my arm but think i lost him for now." << endl;
    cout << " > 6:27...but i lost myself too." << endl;
    cout << " > 6:52...he actually cut me pretty bad. i hope i didnt leave to obvious a blood trail." << endl;
    cout << " > 6:53...please find me soon." << endl;
    cout << endl;
    cout << "Worried about your friend's safety, you quickly send a message back." << endl;
    cout << " <<< 7:33...are u ok? where r u?" << endl;
    cout << " > 7:33...hey! he caught me but i managed to get away before anything else happened." << endl;
    cout << " > 7:34...we must be close now right?" << endl;
    cout << " <<< 7:34...yeah, if these are going through." << endl;
    cout << " > 7:35..so how should i find u?" << endl;
    cout << endl;

    //starting ending stuff here
    //choose route
    cout << "How do you instruct your friend to find you?" << endl;
    cout << "1. Yell and tell him to follow the sound." << endl;
    cout << "2. Tell him to look for your flashlight beam." << endl;
    int endChoice;
    cin >> endChoice;
    while (endChoice != 1 && endChoice != 2){
        cout << "Please choose a valid action." << endl;
        cin >> endChoice;
    }

    if (endChoice == 1){
        cout << "You chose for him to follow noise." << endl;
        cout << " <<< 7:37...i'm gonna yell, can u follow the sound?" << endl;
        cout << " > 7:38...yeah, i think i can do that." << endl;
        cout << endl;
        cout << "You yell his name as loud as you can, and it echoes in the quiet forest." << endl;
        cout << " > 7:38...i heard that to my left! headed there now." << endl;
        cout << endl;
        cout << "Relieved that things finally seem to be over, you eagerly await his arrival." << endl;
        cout << "You hear footsteps pounding to your right." << endl;
        cout << "You turn to finally face your friend, only to feel a sharp pain in your head before everything goes black." << endl;
        cout << endl;
        cout << "... You attracted the killer. Game Over." << endl;
        exit(0);
    }

    if (endChoice == 2){
        if (flashlight == 1){
            cout << "You chose for him to follow your flashlight beam." << endl;
            cout << " <<< 7:37...i'm gonna shine my flashlight. can u look for it?" << endl;
            cout << " > 7:38...yeah i can do that." << endl;
            cout << endl;
            cout << "You shine your flashlight in circles." << endl;
            cout << " > 7:39...i saw that to my left! headed there now." << endl;
            cout << "Relieved that things finally seem to be over, you eagerly await his arrival." << endl;
            cout << "You shine your flashlight intermittently so he doesn't lose his way." << endl;
            cout << "You hear uneven footsteps approach you." << endl;
            cout << "You turn and shine your light on the approaching figure... it's your friend!" << endl;
            cout << "The two of you run back to camp and get to the main road, before calling for help." << endl;
            cout << endl;
            cout << "...You managed to survive and save your friend. Game Over." << endl;
        }

        if (flashlight == 0 && batteryLife == 0){
            cout << "You can't do that! Your battery is dead!" << endl;
            cout << "You have no choice but to locate him through sound." << endl;
            cout << endl;
            cout << " <<< 7:37...i'm gonna yell, can u follow the sound?" << endl;
            cout << " > 7:38...yeah, i think i can do that." << endl;
            cout << endl;
            cout << "You yell his name as loud as you can, and it echoes in the quiet forest." << endl;
            cout << " > 7:38...i heard that to my left! headed there now." << endl;
            cout << endl;
            cout << "Relieved that things finally seem to be over, you eagerly await his arrival." << endl;
            cout << "You hear footsteps pounding to your right." << endl;
            cout << "You turn to finally face your friend, only to feel a sharp pain in your head before everything goes black." << endl;
            cout << endl;
            cout << "... You attracted the killer. Game Over." << endl;
            exit(0);
        }
    }

    return 0;
}