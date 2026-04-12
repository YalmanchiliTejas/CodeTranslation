#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string s,t;

bool solve(char a,char b){
    for (int i=0;i<N;i++) t[i]='X';
    t[0]=a;t[1]=b;
    //cout<<a<<" "<<b<<endl;
    for (int i=0;i<N;i++){
        //cout<<t<<endl;
        int l,r;
        l = (i==0)?N-1:i-1;
        r = (i==N-1)?0:i+1;
        //cout<<l<<" "<<r<<endl;
        if (t[i]=='S') {
            if (s[i]=='o'){
                if (t[l]=='X') t[l] = t[r];
                else if (t[r]=='X') t[r] = t[l];
                else if (t[r]!=t[l]){
                    //cout<<1<<endl;
                    return false;
                }
            }
            if (s[i]=='x'){
                if (t[l]=='X') t[l] = (t[r]=='S')?'W':'S';
                else if (t[r]=='X') t[r] = (t[l]=='S')?'W':'S';
                else if (t[r]==t[l]){
                    //cout<<2<<endl;
                    return false;
                }
            }
        }
        else if (t[i]=='W') {
            if (s[i]=='x'){
                if (t[l]=='X') t[l] = t[r];
                else if (t[r]=='X') t[r] = t[l];
                else if (t[r]!=t[l]){
                    //cout<<3<<endl;
                    return false;
                }
            }
            if (s[i]=='o'){
                if (t[l]=='X') t[l] = (t[r]=='S')?'W':'S';
                else if (t[r]=='X') t[r] = (t[l]=='S')?'W':'S';
                else if (t[r]==t[l]){
                    //cout<<4<<endl;
                    return false;
                }
            }
        }
    }
    return true;
}

int main(void){

    cin>>N>>s;
    for (int i=0;i<N;i++) t.push_back('X');

    bool ans = false;
    if (solve('S','S')){
        cout<<t<<endl;
        return 0;
    }
    if (solve('S','W')){
        cout<<t<<endl;
        return 0;
    }
    if (solve('W','S')){
        cout<<t<<endl;
        return 0;
    }
    if (solve('W','W')){
        cout<<t<<endl;
        return 0;
    }  
    cout<<-1<<endl;
    return 0;
}