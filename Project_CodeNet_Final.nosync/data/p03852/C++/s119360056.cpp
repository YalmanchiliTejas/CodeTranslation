#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str = "aouie" ;
    char j;
    int i ;
    bool flag ;
    cin >> j;
        for (i=0 ; i<5 ; i++)
        {
            if (j == str[i]){
                flag =true;
                break;}

            else{
                flag = false;}  
        }
        if (flag){
            cout <<"vowel"<< endl;}
        else{
            cout <<"consonant" << endl;}
    return 0;
}