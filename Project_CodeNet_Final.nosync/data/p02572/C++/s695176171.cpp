#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int N;
  long long A[200000];
  
  long long total = 0;
  long long kakeru = 0;
  
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> A[i];
    kakeru += A[i];
    
    //cout << kakeru << endl;
  }
  
  for(int i = 0; i < N-1; i++)
  {
    
    kakeru -= A[i];
    
    //cout << A[i] << ' ' << kakeru << ' ';
        
    total += (A[i] * (kakeru % 1000000007)) % 1000000007;
    
    //cout << total << ' ' << endl;
  }
  
  cout << total % 1000000007 << endl;
}