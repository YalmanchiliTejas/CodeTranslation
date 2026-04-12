#include <iostream>
#include <vector>
using namespace std;

vector<bool> used;
vector<int> perm;
vector<vector<int>> path;
int count = 0;

bool check(vector<int> vec, int point){
  for(auto v: vec){
    if(v == point) return true;
  }
  return false;
}

void permutation(int pos, int num){
  if(pos == num){
   	//ポイント同士がつながっているか調べる
    if(!check(path[0], perm[0]+1)) return;
    for(int i=0; i<perm.size(); i++){
      if(i == perm.size()-1){
        count++;
        return;
      }else if(!check(path[perm[i]+1], perm[i+1]+1)){
        return;
      }
    }
  }else{
    for(int i=0; i<num; i++){
      if(!used[i]){
        perm[pos] = i;
        used[i] = true;
        permutation(pos+1, num);
        used[i] = false;
      }
    }
  	return;
  }
}     

int main(){
  int n, m;
  cin >> n >> m;
  for(int i=0; i<n-1; i++){
    used.push_back(false);
    perm.push_back(0);
  }
  for(int i=0; i<n; i++){
    path.push_back(vector<int>());
  }
  for(int i=0; i<m; i++){
    int a, b;
    cin >> a >> b;
    path[a-1].push_back(b-1);
    path[b-1].push_back(a-1);
  }
  permutation(0, n-1);
  cout << count << endl;
  return 0;
}
  