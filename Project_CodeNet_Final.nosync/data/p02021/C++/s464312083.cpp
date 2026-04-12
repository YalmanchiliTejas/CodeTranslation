#include<bits//stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    int d=0;
    int b[a];
    for(int i=0;i<a;i++){
        cin>>b[i];
        d+=b[i];
        b[i]=d/(i+1);
    }
    sort(b,b+a);
    cout<<b[0]<<endl;
}
//私はすだぽんを愛している
