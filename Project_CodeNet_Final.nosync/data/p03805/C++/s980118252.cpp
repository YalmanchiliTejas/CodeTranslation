#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


vector<vector<bool>> G;

bool solve(vector<int> v, int index)
{
  if(index==v.size()-1)
    return true;
  else if(G[v[index]][v[index+1]]==true)
    return solve(v, index+1);
  else
    return false;
}


int main()
{
  int N, M;
  cin >> N >> M;

 G.resize(N);
  for(int i=0; i<N; i++)
    G[i].resize(N);

  
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      G[i][j] = false;
  
  for(int i=0; i<M; i++)
    {
      ll v1, v2;
      cin >> v1 >> v2;
      G[v1-1][v2-1]=true;
      G[v2-1][v1-1]=true;
    }
  
  vector<int> v(N);
  for(int i=0; i<N; i++)
    v[i]=i;

  ll count = 0;
  do
    {
      if(solve(v, 0))
	{
	  //	  for(int i=0; i<v.size(); i++)
	  //cout << v[i] <<" " ;
	  cout << endl;
	  count++;
	}
    }
  while(next_permutation(v.begin()+1, v.end()));


  cout << count << endl;
  
  return 0;
}


//cout << setprecision(13);
//next_permutation();
//__gcd();
//reverse();
//set ,tuple ,pair;
//bitset
//vector.find
//vector.count

