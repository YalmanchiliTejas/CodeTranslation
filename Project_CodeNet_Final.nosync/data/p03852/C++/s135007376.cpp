#include<bits/stdc++.h>
using namespace std;
char a[5]={'a','e','i','o','u'};
int main(){
    char c;
    c=getchar();
    if(c==a[0] || c==a[1] || c==a[2] || c==a[3] || c==a[4])
        cout<<"vowel"<<endl;
    else
        cout<<"consonant"<<endl;
    return 0;
}