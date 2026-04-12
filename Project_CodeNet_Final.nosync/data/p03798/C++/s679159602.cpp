
#include<bits/stdc++.h>

using namespace std;

char re(char c){
        if(c=='S'){
                return 'W';
        }
        else{
                return 'S';
        }
}

int main(){
        int N;
        string s;
        cin>>N>>s;
        bool flag[4][2];
        for(int i=0;i<4;i++){
                flag[i][0]=false;
                flag[i][1]=false;
        }
        string res[4]={"SS", "WW", "SW", "WS"};
        for(int i=0;i<4;i++){
                //create
                for(int j=1;j<N-1;j++){
                        if(s[j]=='o'){
                                if(res[i][j]=='S'){
                                        res[i]+=res[i][j-1];
                                }
                                else if(res[i][j]=='W'){
                                        res[i]+=re(res[i][j-1]);
                                }
                        }
                        else{
                                if(res[i][j]=='S'){
                                        res[i]+=re(res[i][j-1]);
                                }
                                else if(res[i][j]=='W'){
                                        res[i]+=res[i][j-1];
                                }
                        }
                }
                //judge
                if(s[N-1]=='o'){
                        if(res[i][N-1]=='S'){
                                if(res[i][N-2]==res[i][0]){
                                        flag[i][0]=true;
                                }
                        }
                        else{
                                if(res[i][N-2]==re(res[i][0])){
                                        flag[i][0]=true;
                                }
                        }
                }
                else{
                        if(res[i][N-1]=='S'){
                                if(res[i][N-2]==re(res[i][0])){
                                        flag[i][0]=true;
                                }
                        }
                        else{
                                if(res[i][N-2]==res[i][0]){
                                        flag[i][0]=true;
                                }
                        }
                }
                if(s[0]=='o'){
                        if(res[i][0]=='S'){
                                if(res[i][N-1]==res[i][1]){
                                        flag[i][1]=true;
                                }
                        }
                        else{
                                if(res[i][N-1]==re(res[i][1])){
                                        flag[i][1]=true;
                                }
                        }
                }
                else{
                        if(res[i][0]=='S'){
                                if(res[i][N-1]==re(res[i][1])){
                                        flag[i][1]=true;
                                }
                        }
                        else{
                                if(res[i][N-1]==res[i][1]){
                                        flag[i][1]=true;
                                }
                        }
                }
        }
        /*for(int i=0;i<4;i++){
                cout<<res[i]<<endl;
        }*/
        for(int i=0;i<5;i++){
                if(i==4){
                        cout<<-1<<endl;
                        break;
                }
                if(flag[i][0]&&flag[i][1]){
                        cout<<res[i]<<endl;
                        break;
                }
        }
        return 0;
}
