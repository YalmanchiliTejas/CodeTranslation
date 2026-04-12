#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){


char arr[]={'a', 'e', 'i', 'o' ,'u'};
char c;
cin >> c;
for(int i=0;i<5 ;i++){
    if(c==arr[i]) {cout<<"vowel"; return 0;}
}
cout<<"consonant";



return 0;

}

