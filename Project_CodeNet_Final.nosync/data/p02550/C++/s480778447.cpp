#include<bits/stdc++.h>
using namespace std;
const int SIZE = 100010;
long long A[SIZE];
int pos[SIZE];
int main() {
    long long N;
    int x,M;
    cin>>N>>x>>M;
    for(int i=0;i<M;i++)pos[i]=-1;
    A[0]=x;
    pos[x]=0;
    int cycle_len=-1;
    for(int i=1;;i++){
        A[i]=(A[i-1]*A[i-1])%M;
        if(pos[A[i]]!=-1){
            cycle_len=i;
            break;
        }
        pos[A[i]]=i;
    }
    int st=pos[A[cycle_len]];
    long long answer=0;
    for(int i=0;i<cycle_len;i++){
        if(i>=N)break;
        if(i<st)answer+=A[i];
        else{
            long long cnt=(N-st)/(cycle_len-st)+(((N-st)%(cycle_len-st))>(i-st));
            answer+=cnt*A[i];
        }
    }
    cout<<answer<<endl;
    return 0;
}
