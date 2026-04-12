#include<bits/stdc++.h>

using namespace std;

int main(){
        string s;
        cin>>s;
        bool res=false;
        for(int i=0;i<(int)s.length()-1;i++){
                if(s[i]=='A'&&s[i+1]=='C'){
                        res=true;
                }
        }
        if(res){
                cout<<"Yes"<<endl;
        }
        else{
                cout<<"No"<<endl;
        }
        return 0;
}
