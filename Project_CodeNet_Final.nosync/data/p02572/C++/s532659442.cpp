#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

int mod=1000000007;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}


int main(){

int n;
cin>>n;
Vec vec(n);
ll sum=0;
for(int i=0;i<n;i++){
    cin>>vec[i];
    sum+=vec[i];
    sum%=mod;
}
ll ans=0;
for(int i=0;i<n;i++){
    sum-=vec[i];
    if(sum<0){
        sum+=mod;
    }
   ans+=sum*vec[i];
   ans%=mod;
}
cout<<ans<<endl;
}
