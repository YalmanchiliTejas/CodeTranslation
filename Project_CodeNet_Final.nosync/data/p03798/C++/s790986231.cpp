#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int main(){
  int N;
  cin >> N;
  string s;
  cin >> s;

  bool ani[N]; //true 羊　false 狼
  bool ans1_found = false;
  bool ans2_found = false;

  //case1 ssを仮定
  ani[0] = true;
  ani[1] = true;
  for(int i=1;i<N-1;i++){
    if(s[i] == 'o' && ani[i]) ani[i+1] = ani[i-1];
    else if(s[i] == 'o' && !ani[i]) ani[i+1] = !ani[i-1];
    else if(s[i] == 'x' && ani[i]) ani[i+1] = !ani[i-1];
    else if(s[i] == 'x' && !ani[i]) ani[i+1] = ani[i-1];
  }
  if(s[N-1] == 'o' && ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
  if(s[N-1] == 'o' && !ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
  if(s[N-1] == 'x' && ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
  if(s[N-1] == 'x' && !ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
  if(s[0] == 'o' && ani[0] && ani[N-1] == ani[1]) ans2_found = true;
  if(s[0] == 'o' && !ani[0] && ani[N-1] != ani[1]) ans2_found = true;
  if(s[0] == 'x' && ani[0] && ani[N-1] != ani[1]) ans2_found = true;
  if(s[0] == 'x' && !ani[0] && ani[N-1] == ani[1]) ans2_found = true;


  //case2 swを仮定
  if(!ans1_found || !ans2_found){
    ans1_found = false;
    ans2_found = false;
    ani[0] = true;
    ani[1] = false;
    for(int i=1;i<N-1;i++){
      if(s[i] == 'o' && ani[i]) ani[i+1] = ani[i-1];
      else if(s[i] == 'o' && !ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && !ani[i]) ani[i+1] = ani[i-1];
    }
    if(s[N-1] == 'o' && ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[N-1] == 'o' && !ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && !ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[0] == 'o' && ani[0] && ani[N-1] == ani[1]) ans2_found = true;
    if(s[0] == 'o' && !ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && !ani[0] && ani[N-1] == ani[1]) ans2_found = true;
  }

  //case3 wsを仮定
  if(!ans1_found || !ans2_found){
    ans1_found = false;
    ans2_found = false;
    ani[0] = false;
    ani[1] = true;
    for(int i=1;i<N-1;i++){
      if(s[i] == 'o' && ani[i]) ani[i+1] = ani[i-1];
      else if(s[i] == 'o' && !ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && !ani[i]) ani[i+1] = ani[i-1];
    }
    if(s[N-1] == 'o' && ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[N-1] == 'o' && !ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && !ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[0] == 'o' && ani[0] && ani[N-1] == ani[1]) ans2_found = true;
    if(s[0] == 'o' && !ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && !ani[0] && ani[N-1] == ani[1]) ans2_found = true;
  }

  //case4 wwを仮定
  if(!ans1_found || !ans2_found){
    ans1_found = false;
    ans2_found = false;
    ani[0] = false;
    ani[1] = false;
    for(int i=1;i<N-1;i++){
      if(s[i] == 'o' && ani[i]) ani[i+1] = ani[i-1];
      else if(s[i] == 'o' && !ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && ani[i]) ani[i+1] = !ani[i-1];
      else if(s[i] == 'x' && !ani[i]) ani[i+1] = ani[i-1];
    }
    if(s[N-1] == 'o' && ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[N-1] == 'o' && !ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && ani[N-1] && ani[N-2] != ani[0]) ans1_found = true;
    if(s[N-1] == 'x' && !ani[N-1] && ani[N-2] == ani[0]) ans1_found = true;
    if(s[0] == 'o' && ani[0] && ani[N-1] == ani[1]) ans2_found = true;
    if(s[0] == 'o' && !ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && ani[0] && ani[N-1] != ani[1]) ans2_found = true;
    if(s[0] == 'x' && !ani[0] && ani[N-1] == ani[1]) ans2_found = true;
  }

  if(!ans1_found || !ans2_found) cout << -1 << endl;
  else {
    for(int i=0;i<N;i++){
      if(ani[i]) cout << 'S';
      else cout << 'W';
    }
    cout << endl;
  }

  return 0;
}
