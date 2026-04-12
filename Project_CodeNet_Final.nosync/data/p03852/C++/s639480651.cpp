#include<bits/stdc++.h>
using namespace std;
#define ll long long
const unsigned int M = 1000000007;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char c;
    while(cin>>c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')cout<<"vowel"<<endl;
        else cout<<"consonant"<<endl;
    }
    return 0;
}
