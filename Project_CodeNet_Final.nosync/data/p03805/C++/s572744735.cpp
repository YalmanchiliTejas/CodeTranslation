#include <iostream>
#include <vector>
using namespace std;

int sum=0;
vector<vector<int> > v;
vector<bool>l;
int n,m;

void dfs(int p,int num)
{
  if(num==n)
    sum++;
  else{
    l[p]=false;

    for(auto z:v[p]){
      if(l[z]==true)
        dfs(z,num+1);
    }

    l[p]=true;
  }
}


int main()
{
  cin >> n >> m;
  v.resize(n);
  l.resize(n,true);

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(0,1);

  cout << sum << endl;

}