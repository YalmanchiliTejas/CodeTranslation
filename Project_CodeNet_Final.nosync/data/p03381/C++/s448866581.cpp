#include<bits/stdc++.h>
using namespace std;
struct data{
    int value;
    int order;
};
bool order(data a, data b){
    return a.value < b.value;
}
data seq[200200];
int i,n,d,pos,ans[200200];
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&d);
        seq[i].value=d;
        seq[i].order=i;
    }
    pos=n/2;
    sort(seq+1,seq+n+1,order);
    /*for(i=1;i<=n;i++){
        cout << seq[i].order << seq[i].value << endl;
    }*/
    for(i=1;i<=n;i++){
        if(i<=pos){
            ans[seq[i].order]=seq[pos+1].value;
        }
        else{
            ans[seq[i].order]=seq[pos].value;
        }
    }
    for(i=1;i<=n;i++){
        cout << ans[i] << endl;
    }
}
