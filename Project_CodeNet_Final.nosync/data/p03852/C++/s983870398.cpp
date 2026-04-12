#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    char c;
    c=getchar();
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        cout<<"vowel"<<endl;
        else cout<<"consonant"<<endl;
    return 0;
}