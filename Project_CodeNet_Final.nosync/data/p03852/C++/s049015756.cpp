#include <iostream>
#include <string>

using namespace std;

int main()

{
   string x = "aeouiAEOUI";
   int counter=0;
   char c;
   cin>>c;

   for (int i=0;i<10;i++){
       if (x[i]==c){
        counter++;
        break;
       }

   }
   if (counter==0){
    cout<<"consonant"<<endl;
   }
   else{
    cout<<"vowel"<<endl;
   }
    return 0;
    }