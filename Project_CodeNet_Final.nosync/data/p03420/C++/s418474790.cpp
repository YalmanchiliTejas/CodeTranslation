#include <iostream>
#include <cstdio>

using namespace std;
int a[20][20];
int main()
{
    int n,k;
    cin>>n>>k;
    long long cnt=0;
    if(!k){
        cout<<(long long)n*n<<endl;
        return 0;
    }
    for(int i=k;i<=n-1;i++){
        //cout<<(i-k+1)* (n/(i+1))<<endl;
        cnt += (i-k+1)* (n/(i+1));
        if(n%(i+1)-k>=0){
            cnt+= n%(i+1)-k +1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
