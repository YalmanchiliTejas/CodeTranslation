#include <iostream>
using namespace std;
#define LIMIT 1000000

int main(){
    int n;
    while(cin>>n&&n){
        int d[LIMIT];
        int go[LIMIT];
        for(int i=1; i<=n; i++){
            cin>>d[i];
        }
        for(int i=1; i<=n; i++){
            if(i%2==1){
                go[i]=d[i];
            }else{
                if(d[i]==d[i-1]) go[i]=d[i];
                else if(d[i]==1){
                    for(int j=i-1; go[j]!=1; j--) go[j]=1;
                    go[i]=d[i];
                }else if(d[i]==0){
                    for(int j=i-1; go[j]!=0&&j>=1; j--) go[j]=0;
                    go[i]=d[i];
                }
            }
        }
        
        int sum=0;
        for(int i=1; i<=n; i++){
            if(go[i]==0) sum++;
        }
        cout << sum << endl;
    }
}