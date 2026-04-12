#include <bits/stdc++.h>
using namespace std;

// bool evenNumberOfOnesInBinary(int number){
//     int count = 0;
//     while(number>0){
//         if(number%2!=0) count++;
//         number = number/2;
//     }
//     return count%2==0;
// }

bool evenNumberOfOnesInBinary(long long int x)
{
    long long int y = x ^ (x >> 1);
    y = y ^ (y >> 2);
    y = y ^ (y >> 4);
    y = y ^ (y >> 8);
    y = y ^ (y >> 16);
   if (y & 1)
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S; cin>>S;
    int a = 0, b = 0;
    for(int i=0; i<3; ++i){
        if(S[i]=='A') a = 1;
        if(S[i]=='B') b= 1;
    }
        if(a && b) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
}