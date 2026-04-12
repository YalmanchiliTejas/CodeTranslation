#include <bits/stdc++.h>
using namespace std;
int main() {
// m Restaurant
int N,x=0,z=0;
cin>>N;
if(1<=N&&N<=100){
x=N*800;
z=N/15;
x-=(z*200);
}
    printf("%d",x);
    return 0;
}

