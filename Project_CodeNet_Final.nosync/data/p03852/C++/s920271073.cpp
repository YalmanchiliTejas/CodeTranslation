#include <iostream>
#include <string>
using namespace std;
char x;
char z[]={'a','e','u','i','o'};
int main(){
   cin>>x;
   int c=0;
   for(int i=0;i<=4;i++)
   {
        if (z[i]==x)
        {
            c += 1;
        }
    }
    if(c>0){
        cout<<"vowel"<<endl;
    } else {
        cout << "consonant" << endl;
    }

}