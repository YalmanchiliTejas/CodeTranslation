#include<bits/stdc++.h>
using namespace std;
int n,igo[100005],a,white,black;

int main(){

    while(1){
            white=0;

    cin >> n;
    if(n==0)break;

    cin >> igo[1];

    for(int i=2;i<=n;i++){
        cin >> a;
        if(i%2==0){
        if(a!=igo[i-1]){
            for(int j=i-1;j>0;j--){
                if(igo[j]==a)break;
                else igo[j]=a;
                }
                igo[i]=a;
            }else igo[i]=a;
        }else igo[i]=a;
    }

    for(int i=1;i<=n;i++){
        if(igo[i]==0)white++;
    }

    cout << white << endl;
    //for(int i=1;i<=n;i++)cout << igo[i];
    //cout << endl;


    }

return 0;
}