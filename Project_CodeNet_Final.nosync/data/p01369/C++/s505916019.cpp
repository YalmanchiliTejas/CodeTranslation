#include <bits/stdc++.h>
using namespace std;

int check(char c){
    if( (c >= 'h' && c<='p') || c == 'y' || c == 'u') return 1;

    else return 0;
}

int main(){
    while(1){
        string s; cin>>s;
        if(s == "#") break;

        int count = 0;

        for(int i=1; i<s.size(); i++){
            if(check(s[i-1]) != check(s[i]))count++;
        }

        cout<<count<<endl;

    }

    return 0;
}
