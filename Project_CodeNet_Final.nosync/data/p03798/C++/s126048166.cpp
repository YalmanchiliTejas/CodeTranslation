#include<bits/stdc++.h>
using namespace std;

bool correct(char ver, int i, string answer, char ins){
    if(ver=='o'){
        if((answer[(i-1<0?i-1+answer.size():i-1)]=='S'&&answer[i]=='S')||(answer[(i-1<0?i-1+answer.size():i-1)]=='W'&&answer[i]=='W')){
            return ins=='S';
        }
        else{
            return ins!='S';
        }
    }
    else{
        if((answer[(i-1<0?i-1+answer.size():i-1)]=='S'&&answer[i]=='S')||(answer[(i-1<0?i-1+answer.size():i-1)]=='W'&&answer[i]=='W')){
            return ins!='S';
        }
        else{
            return ins=='S';
        }
    }
}

int main(){
    int n; string s, option[4] = {"SS", "SW", "WS", "WW"};
    cin>>n>>s;
    for( int i = 0; i < 4; i++ ){
        string answer = option[i];
        for( int j = 1; j < s.size()-1; j++ ){
            if(s[j]=='o'){
                if(correct('o',j, answer, 'S')){
                    answer+='S';
                }
                else{ answer+='W';}
            }
            else{
                if(correct('x',j, answer, 'S')){
                    answer+='S';
                }
                else{ answer+='W';}
            }
        }
        if((correct(s[s.size()-1], s.size()-1, answer, answer[0]))&&(correct(s[0], 0, answer, answer[1]))){
            cout<<answer<<endl; return 0;
        }
    }
    cout<<-1;
    return 0;
}