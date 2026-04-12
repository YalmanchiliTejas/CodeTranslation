// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1147&lang=jp
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;

  while(cin>>n&&n!=0){
    vector<int> score(n);
    for(int i=0;i<n;++i)
      cin>>score[i];

    sort(score.begin(), score.end());

    cout<<accumulate(score.begin()+1,score.end()-1,0)/(score.size()-2)<<endl;
  }

  return EXIT_SUCCESS;
}