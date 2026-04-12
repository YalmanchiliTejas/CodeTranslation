#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7ll;

int N;
string S;
int K;

int main(){

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>S>>K;

int n=S.size();

char c;
for(int i=0; i<n; i++){
  if(i==K-1){
    c=S[i];
  }
}

for(int i=0; i<n; i++){
  if(S[i]!=c){
    S[i]='*';
  }
}

cout<<S<<endl;

}

