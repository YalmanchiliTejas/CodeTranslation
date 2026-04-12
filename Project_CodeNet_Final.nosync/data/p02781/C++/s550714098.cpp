#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin >> s;
    int t;cin >> t;
    int n=s.size();
    string u="";
    for(int i=0;i<n;i++){
        u+='0';
    }
    if(n<t){
        cout << 0 << endl;
        return 0;
    }
    long long ans=0;
    string q;
    if(t==1){
        for(int i=0;i<n;i++){
            for(char x='1';x<='9';x++){
                q=u;
                q[i]=x;
                if(q<=s){
                    ans++;
                }
            }
        }
    }
    else if(t==2){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(char x='1';x<='9';x++){
                    for(char y='1';y<='9';y++){
                        q=u;
                        q[i]=x;
                        q[j]=y;
                        if(q<=s){
                            ans++;
                        }
                    }
                }
            }
        }
   }
    else{
        ans+=(n-1)*(n-2)*(n-3)/6*9*9*9;
            for(int j=1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(char x='1';x<='9';x++){
                        for(char y='1';y<='9';y++){
                            for(int z='1';z<='9';z++){
                                q=u;
                                q[0]=x;
                                q[j]=y;
                                q[k]=z;
                                if(q<=s){
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
    }
    cout << ans << endl;
}