#include<bits/stdc++.h>
using namespace std;
int main(){
char a;
char c[]={'a','e','o','u','i'};
cin>>a;
for (int i=0;i<5;i++)
    if (a==c[i]){
        cout<<"vowel";
        return 0;}
cout<<"consonant";
return 0;
}