// Menagerie
#include <iostream>
#include <string>
using namespace std;

int n;
int a[100001]; // 0が狼、1が羊
string s;

int main(){
    cin>>n>>s;
    for(int a0=0;a0<=1;a0++){
        a[0]=a0;
        for(int a1=0;a1<=1;a1++){
            a[1]=a1;
            for(int i=1;i<n;i++){
                if(a[i]^s[i]=='o') a[i+1]=1-a[i-1];
                else a[i+1]=a[i-1];
            }
            if(a[n]==a[0]&&(a[0]^s[0]=='o'^a[1]==a[n-1])){
                for(int i=0;i<n;i++){
                    if(a[i]) cout<<'S';
                    else cout<<'W';
                }
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}