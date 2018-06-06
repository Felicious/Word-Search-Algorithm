#include "header.h"

int main(){
   vector<vector<char>> v;
   v.push_back(vector<char>());
   ifstream in("spuzzle.txt");
   if(in.fail()){
       cout << "can't open file! ):" << endl;
       return 1;
   }
   string line;
   //number of rows and columns in puzzle
   int nrows(0), ncols(0);
   
   //creates the puzzle and finds out the # of rows and columns
   if(getline(in,line)){
       ++nrows;
       for(auto &e: line)//loops through line, which is a vector. auto == char
           if(e != ' ')
               v[0].push_back(e);
       ncols = line.size();
   }
   
   while(getline(in, line)){ //reads word puzzle, line by line 
       //create vector object that I will use to parse through and search for words
       vector<char> temp;
       for (auto &e : line)
           if (e != ' '){
               temp.push_back(e);
               v.push_back(temp);
           }
       ++nrows;
   }
   in.close();
   set<string> dictionary(create_d());
   set<word_coord> ans;
   
   //actual searching starts here!
   for (int i(0); i < nrows; ++i) 
       for (int j(0); j < ncols; ++j)
           for (int x(-1); x <= 1; ++x) // x= horizontal position
               for (int y(-1); y <= 1; ++y){ // y= vertical position
                   string w;
                   int xpos = i;
                   int ypos = j;
                   while (((xpos + x) >= 0) && ((ypos + y) >= 0) && ((xpos + x) < nrows) && ((j + ypos) < ncols) && ((x != 0) || (y != 0))){
                       xpos += x;
                       ypos += y;
                       w += v.at(xpos).at(ypos);
                       if(6 <= w.size())
                           for(auto &f: dictionary)
                               if(w == f){
                                   word_coord temp;
                                   temp.w = w;
                                   temp.begin.first = i;
                                   temp.begin.second = j;
                                   temp.end.first = xpos;
                                   temp.end.second = ypos;
                                   ans.insert(temp);
                               }
                   }
               }
   for(auto &g: ans)
       cout << g.w <<" ("<<g.begin.first<<", "<<g.begin.second<<") to ("<<g.end.first<<", ("<<g.end.second<<")"<<endl;
   return 0;
}
