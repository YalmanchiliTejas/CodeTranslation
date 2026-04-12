#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string code;
    while(cin>>code){
        int Lflag=0,Rflag=0,cnt=0;
        if(code[0]=='#')break;
        for(int i=0;i<code.size();i++){
            if(code[i]=='y'||code[i]=='u'||code[i]=='i'||code[i]=='o'||code[i]=='p'||code[i]=='h'||code[i]=='j'||code[i]=='k'||code[i]=='l'||code[i]=='n'||code[i]=='m'){
                if(Lflag==1){
                    Rflag=1;Lflag=0;
                    cnt++;
                }
                else Rflag=1;
            }
            else{
                if(Rflag==1){
                    Rflag=0;Lflag=1;
                    cnt++;
                }
                else Lflag=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}