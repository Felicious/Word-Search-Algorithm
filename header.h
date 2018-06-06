#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//class that allows me to keep track of starting letter to search  
class word_coord{
public:
   string w;
   pair<int,int> begin;
   pair<int,int> end;
};
bool operator < (const string &l) const {
   return (l < l.w);
}

//functions we need:
//1. reads dictionary
set<string> create_d(){
   set<string> d;
   ifstream ds("words.txt"); //takes in txt file containing word puzzle (word puzzle given by professor was called "words.txt") 
   string w,x,y;
   while(ds >> w){
       if(w.size() >= 6)
           d.insert(w);
   }
   ds.close();
   return d;
}
