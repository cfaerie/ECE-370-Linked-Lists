#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct node{
    string name; //program might be having an issue with not resizing string
    int score;
    node *link;
    node();
};

node::node(){
     //zero the node out by default
    link = NULL;

}
int listLen = 0;

void printList(node *&firstEntry){
    node *currentEntry;
    currentEntry = new node;
    currentEntry = firstEntry;

    bool done = false;

    while(done!=true){
        cout<<currentEntry->name<<"\t"<<currentEntry->score<<endl;
        if(currentEntry->link!=NULL){
            currentEntry = currentEntry->link;
        }
        else{
            done = true;
        }
    }
}//printList


void insertion(node *&firstEntry, node *&newEntry){
    //Insertion function
    //insert a node where it should be to maintain alphabetical order
    //if an existing node contains the same name, the one being inserted will overwrite the existing node
    //node *temp;
    //temp = new node;

    node *currentEntry;
    currentEntry = new node;
    currentEntry = firstEntry;//initially
/*
    node *nextEntry;
    nextEntry = new node;
    nextEntry = currentEntry->link;
*/
    bool done = false;

 /*   string fName, cName, nxtName, newName;
    fName = firstEntry->name;//won't change
    cName = currentEntry->name;
    nxtName = nextEntry->name;
    newName = newEntry->name;
    */

    while(done == false){

    //need to loop here while we go down the entries
    //at end of loop, set current entry to be next entry

    if(firstEntry->name.size()<=1){
        //if the first entry of the linked list has a name with no characters, then the list is empty
        //just make the new entry the first on the list
        firstEntry->name = newEntry->name;
        firstEntry->score = newEntry->score;

        listLen++;

        done = true;
    }
/*
    else if((fName.compare(newName) > 0) && (nxtName.compare(newName) > 0)){
        //then newEntry belongs at the beginning of the list
        newEntry->link = firstEntry;
        firstEntry = newEntry;

        //store link of previous
        done = true;
    }
    *.
    /*
    else if((currentEntry->name < newEntry->name)&&(nextEntry->name > newEntry->name)){
        //if currentEntry is alphabetically before newEntry and
        //next entry is alphabetically after newEntry
        //Place new Entry in between them
        newEntry->link = nextEntry;
        currentEntry->link = newEntry;

        done = true;
    }
    else if((nextEntry->name < newEntry->name)==true){
        //then newEntry belongs at end of the list, after nextEntry

        nextEntry->link = newEntry;

        done = true;
    }
*/
    else if(currentEntry->link==NULL){
        //put new entry at end of the list
        currentEntry->link = newEntry;
        listLen++;
        done = true;
    }
    //End of loop, set current entry to be next entry
    currentEntry = currentEntry->link;
    }//while
    //printList(firstEntry);
}
void deletion(node *&firstEntry,string name){//NOT WORKING
    //given a name, delete that node from the list if it exists
    node *prevEntry;
    prevEntry = new node;

    node *currentEntry;
    currentEntry = new node;

    currentEntry = firstEntry;
    prevEntry = currentEntry;//for now

    bool deleted = false;

    while(deleted == false){
        if(currentEntry->name==name){
                if(prevEntry==currentEntry){
                    firstEntry = currentEntry->link;
                }
                else{
                  prevEntry->link = currentEntry->link;
                }
            deleted = true;
            listLen--;
        }
        prevEntry = currentEntry;
        currentEntry = currentEntry->link;
    }

}
void searchName(node *&firstEntry, string name){ //functional
    //Search for a node with the given name
    //If found, print the name and score on a single line
    //If not found, Print "Not Found"
    //Search cannot change the info in the list
    bool found = false;

    node *currentEntry;
    currentEntry = new node;
    currentEntry = firstEntry;//initially
    cout<<"\n Search Result: "<<endl;

    while(found==false && currentEntry->link != NULL){

        if(currentEntry->name == name){
            //name must be in ALL CAPS
            cout<<currentEntry->name<<"\t"<<currentEntry->score<<endl;
            found = true;
        }
        else if(currentEntry->link==NULL){
            cout<<name<<" was not found. \n Make sure name is entered in ALL CAPS"<<endl;
        }
        currentEntry = currentEntry->link;
    }

}
void SORTASC(node *&firstEntry){//NOT WORKING
    //function to handle sorting the linked list in ascending order by score
    //using bubblesort because it is easy to get correct with few errors
    int i,j;

    node *temp;
    temp = new node;

    node *currentEntry;
    currentEntry = new node;


    node *prevEntry;//we just need the link from this node
    prevEntry = new node;


    node *nextEntry;
    nextEntry = new node;


    node *holdCurrent; //this node will not have it's values changed individually
    holdCurrent = new node;
    holdCurrent = firstEntry;

    for(i=0;i<listLen;i++){
            currentEntry = firstEntry;//initially
            prevEntry = currentEntry; //just to start
            nextEntry = currentEntry->link;
        for(j=0;j<listLen;j++){
            if(nextEntry->score < currentEntry->score){
                //if next entry is smaller than current entry, swap
                if(currentEntry == prevEntry){
                    //if the previous linker is firstEntry
                    temp->link = nextEntry->link;
                    nextEntry->link = currentEntry;
                    firstEntry = nextEntry;
                    currentEntry->link = temp->link;

                    currentEntry = holdCurrent->link;
                    nextEntry = currentEntry->link;
                }
                else{
                    prevEntry->link = nextEntry;
                    temp->link = nextEntry->link;
                    nextEntry->link = currentEntry;
                    currentEntry->link = temp->link;

                    prevEntry = holdCurrent;
                    currentEntry = holdCurrent->link;
                    nextEntry = currentEntry->link;
                }
                holdCurrent = holdCurrent->link;

            }
        }
    }
}
void SORTDES(){
    //Function to handle sorting the linked list in descending order by score
}

int main()
{
    ifstream inFile;
    inFile.open("a5.txt");
    string last, next, next2;


    node *firstEntry;
    firstEntry = new node;

    node *newEntry;

    bool breaker = false;

    while(breaker == false){
            //newEntry = new node;
            inFile>>next;
            next2 = "\0";
        if((int(next[0])>=65) && (int(next[0])<=90)){
            //if the first char of next is an A-Z ASCII value, then it is a name
            //only works for uppercase though
            //check if next2 is a number
            newEntry->name = string(next);
            inFile>>next2;

            if((int(next2[0])>=48) && (int(next2[0]<=57))){
            //if the first char of next2 is an integer 0-9, then it is a number
            //call insertion function

            newEntry->score = atoi(next2.c_str());
            //cout<<"Test: "<<atoi(next2.c_str())<<endl;

        }
        insertion(firstEntry,newEntry);
        }
        if(int(next[0])==37){
            //if the first char of next is a %, then it is a command
            //figure out which command and then call appropriate function to handle it
            cout<<next<<endl;
            if(next=="%VISIT"){//correct and done
                        printList(firstEntry);
            }
            if(next=="%SORTASC"){
                        //sort list in ascending order by scores
            }
            if(next=="SORTDEC"){
                        //sort list in descending order by scores
            }
            if(next=="%END"){

                breaker = true;
            }
        }
        //cout<<"Test: "<<next<<"\t"<<next2<<endl;


    }//while
    printList(firstEntry);
    cout<<listLen<<endl;

    return 0;
}
