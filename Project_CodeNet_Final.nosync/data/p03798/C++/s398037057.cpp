#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s;
    cout.tie(NULL);
    // 0->wolf 1->sheep
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            int a=i,b=j,c;
            for(int k=1;k<n;k++){
                if(s[k]=='o'){
                    if(b==0){
                        c=1-a;
                    }
                    else{
                        c=a;
                    }
                }
                else{
                    if(b==0){
                        c=a;
                    }
                    else{
                        c=1-a;
                    }
                }
                a=b;
                b=c;
            }
            if(b==i){
                bool f=0;
                if(s[0]=='o'){
                    if(i==0&&j!=a){
                        f=1; 
                    }
                    if(i==1&&j==a){
                        f=1;
                    }
                }
                else{
                    if(i==0&&j==a){
                        f=1; 
                    }
                    if(i==1&&j!=a){
                        f=1;
                    }
                }
                if(!f)continue;
                int a=i,b=j,c;
                cout<<(a?'S':'W');
                for(int k=1;k<n;k++){
                    if(s[k]=='o'){
                        if(b==0){
                            c=1-a;
                        }
                        else{
                            c=a;
                        }
                    }
                    else{
                        if(b==0){
                            c=a;
                        }
                        else{
                            c=1-a;
                        }
                    }
                    a=b;
                    b=c;
                    cout<<(a?'S':'W');
                }
                return 0;
            }
        }
    }
    cout<<-1<<endl;
}
