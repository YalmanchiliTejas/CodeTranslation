#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;

int N;
P X[200005];
int idx[200005];

int main() {

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N; 

for(int i=0; i<N; i++){
  cin>>X[i].first;
  X[i].second=i;
}

sort(X,X+N);

for(int i=0; i<N; i++){
  idx[X[i].second]=i;
}

for(int i=0; i<N; i++){
  if(idx[i]<N/2){
    cout<<X[N/2].first<<endl;
  }else{
    cout<<X[N/2-1].first<<endl;
  }

}

}
