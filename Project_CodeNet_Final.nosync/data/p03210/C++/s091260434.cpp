#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<numeric>
#include<set>
#include<string>
#include<utility>
#include<vector>

#define YES cout << "YES" << endl
#define NO  cout << "NO"  << endl
#define rep(i, a, n)  for(int i=a; i<n; i++)
#define per(i, a, n)  for(int i=n-1; i>=a; i--)
#define all(x)  (x).begin(), (x).end()
#define MAX 100001
using namespace std;
typedef long long ll;

int main(){
  int n;  cin >> n;
  if(n==3 or n==5 or n==7){
    YES;
  }else{
    NO;
  }
  return 0;
}
