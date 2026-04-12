#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <map> // pair

using std::sort;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;
using std::reverse;
typedef long long ll;


#define pb push_back
#define mp std::make_pair
#define all(x) (x).begin(),(x).end()

int main() {
  int N;
  cin>>N;
  int ans = 0;
  int h;int maxh = 0;
  
  for(int i = 0;i < N;i++){
    cin>>h;

    if(h >= maxh){
      maxh = h;
      ans++;
    }
  }
  
  cout<<ans;
	return 0;
}
