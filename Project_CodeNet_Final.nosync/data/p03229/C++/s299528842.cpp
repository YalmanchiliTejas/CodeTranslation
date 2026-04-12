#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  long long N;cin>>N;
  vector<long long> A(N);
  for(long long i = 0; N > i; i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  if(N%2){
    long long a = 0;
    long long n = 1;
    long long m = N-1;
    long long t0 = A[0];
    long long t1 = A[0];
    while(n<m){
      a += abs(t0-A[m]);t0=A[m];m--;
      a += abs(t1-A[m]);t1=A[m];m--;
      if(n >= m)break;
      a += abs(t0-A[n]);t0=A[n];n++;
      a += abs(t1-A[n]);t1=A[n];n++;
    }
    sort(A.begin(),A.end(),greater<long long>());
    long long b = 0;
    n = 1;
    m = N-1;
    t0 = A[0];
    t1 = A[0];
    while(n<m){
      b += abs(t0-A[m]);t0=A[m];m--;
      b += abs(t1-A[m]);t1=A[m];m--;
      if(n >= m)break;
      b += abs(t0-A[n]);t0=A[n];n++;
      b += abs(t1-A[n]);t1=A[n];n++;
    }
    cout << max(a,b) << endl;

  }else{
    long long a = 0;
    long long n = 1;
    long long m = N-1;
    long long t0 = A[0];
    long long t1 = A[0];
    while(n<m){
      a += abs(t0-A[m]);t0=A[m];m--;
      a += abs(t1-A[m]);t1=A[m];m--;
      if(n >= m)break;
      a += abs(t0-A[n]);t0=A[n];n++;
      a += abs(t1-A[n]);t1=A[n];n++;
    }
    cout << a+max(abs(t1-A[n]),abs(t0-A[n])) << endl;
  }
}
