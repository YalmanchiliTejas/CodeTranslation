#include<bits/stdc++.h>
using namespace std;
    
int main()
{
  long long N; 
  cin >> N;
  vector<long long> arr(N);
  for(long long i = 0 ; i < N ; i++)
  cin >> arr[i];

    long long sumprod = 0;

    long long sum = 0;
    for(long long i = 0 ; i < N ; i++)
    sum += arr[i];

    vector<long long> sumTillN = arr;
    for(long long i = 1 ; i < N ; i++)
    {
        sumTillN[i] += sumTillN[i-1]; 
    }


  for(long long i = 0 ; i < N ; i++)
  {

      sumprod += ( (arr[i] % 1000000007) * ((sum-sumTillN[i])%1000000007) ) %1000000007;
  
  }

    cout << sumprod % 1000000007;
}