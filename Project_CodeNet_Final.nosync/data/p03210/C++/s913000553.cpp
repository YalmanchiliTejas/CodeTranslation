#include <bits/stdc++.h>

#define ll long long int
#define INFTY (1<<21)

using namespace std;

int main(void){
    cin.sync_with_stdio(false);
    int N;
    cin>>N;
    switch(N){
        case 7:
        case 5:
        case 3:
            cout<<"YES"<<endl;
            break;
        default:
            cout<<"NO"<<endl;
            break;
    }
    return 0;
}