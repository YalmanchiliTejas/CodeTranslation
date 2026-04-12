#include <iostream>

using namespace std;
long long size[51];
long long paty[51];

long long answer(int l, long long x){
    if(l==0 && x==1) return 1;
    if(x==0) return 0;
    long long a = size[l-1];
    if(x <= 1+a) return answer(l-1,x-1);
    else if(x == 2+a) return paty[l-1] + 1;
    else if(2+a<x && x<=2*a+2) return answer(l-1,x-a-2) + paty[l-1] + 1;
    else return paty[l];
}
int main(){
    int N;
    long long X;
    cin >> N >> X;
    size[0] = 1;
    paty[0] = 1;
    for(int i=1; i<N+1; i++){
        size[i] = 3+2*size[i-1];
        paty[i] = 1+2*paty[i-1];
    }
    long long ans = answer(N,X);
    cout << ans << endl;
    return 0;
}

