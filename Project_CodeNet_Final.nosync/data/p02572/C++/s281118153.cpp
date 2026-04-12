#include<bits/stdc++.h>
using namespace std;

int main(void)
{   int n;
    long long int f =1e9+7;
    cin>>n;
    vector<long long int> shihao;
    for(int i=0;i<n;i++)
    {
        long long int h;
        cin>>h;
        shihao.push_back(h);
    }
    vector<long long int> sum;
    long long int sum1=0;
    for(int i=1;i<n;i++)
    {
        sum1=sum1+shihao[shihao.size()-i];
        sum.push_back(sum1%f);
    }
    long long int sum2=0;
    for(int i=0;i<n-1;i++)
    {
        sum2=(sum2+(shihao[i]*sum[n-1-i-1])%f)%f;
    }

    cout<<sum2%f;
    return 0;
}

