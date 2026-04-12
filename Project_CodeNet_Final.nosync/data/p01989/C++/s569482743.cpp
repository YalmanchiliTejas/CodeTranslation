#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    int i,j,k,ans=0,num;
    
    vector<string>ss(4);
    vector<int>si(4);
    for(int i=0;i<s.size()-2;i++){
        for(int j=i+1;j<s.size()-1;j++){
            for(int k=j+1;k<s.size();k++){
                
                ss[0]=s.substr(0,i+1);
                ss[1]=s.substr(i+1,j-i);
                ss[2]=s.substr(j+1,k-j);
                ss[3]=s.substr(k+1);
                

                bool flag=true;
                for(int l=0;l<4;l++){
                    if(ss[l].size()>3||ss[l].size()==0)flag=false;
                    if(ss[l][0]=='0'&&ss[l].size()!=1)flag=false;
                    num=atoi(ss[l].c_str());
                    //cout<<num<<endl;
                    if(!(0<=num&&num<256))flag=false;
                }

                //if(flag)cout<<ss[0]<<" "<<ss[1]<<" "<<ss[2]<<" "<<ss[3]<<endl;
                ans+=flag;
            }

        }
    }
    cout<<ans<<endl;

    return 0;
}
