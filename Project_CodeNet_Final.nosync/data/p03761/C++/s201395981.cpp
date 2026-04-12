#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a[100];
    string ans="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(char i='a';i<='z';i++){
        int mcount=10000;
        for(int j=1;j<=n;j++){
            int count=0;
            for(int k=0;k<a[j].size();k++){
                if(a[j][k]==i)
                    count++;
            }
            if(count==0){
                mcount=10000;
                break;
            }
            mcount=min(mcount,count);
        }
        if(mcount!=10000){
            for(int k=1;k<=mcount;k++){
                ans+=i;
            }
        }
    }
    cout<<ans;
}