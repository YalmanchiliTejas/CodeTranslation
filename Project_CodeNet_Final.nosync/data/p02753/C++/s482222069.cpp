#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

#define __ { \
	freopen("input.txt","r",stdin); \
	freopen("output.txt","w",stdout); \
}
#define _ { \
	ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
}

int main(){
   _;
  // __;
   string s;cin>>s;
   if(s=="AAA"||s=="BBB")cout<<"No";
   else cout<<"Yes";
}