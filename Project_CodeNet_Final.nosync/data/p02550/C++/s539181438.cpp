#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N,A0,M;
  cin >> N >> A0 >> M;

  unordered_map<int64_t, int> data;
  vector<int64_t> cumsum;
  int64_t cs= 0;
  cumsum.emplace_back(cs);

  int64_t Ai= A0 % M;
  int cnt= 1;
  while(!data.count(Ai)){
    data[Ai]= cnt;
    cs+= Ai;
    cumsum.emplace_back(cs);

    Ai= (Ai* Ai) % M;
    cnt++;
  }
  int s_loop= data.at(Ai); 
  int len_cycle= int(cumsum.size())- s_loop;
  int64_t Nloop= (N- (s_loop-1))/ len_cycle;
  int64_t Nrem = (N- (s_loop-1))% len_cycle;

  int64_t sum_cycle= cumsum.back()- cumsum.at(s_loop-1);
  int64_t sum_remain= cumsum.at(s_loop+ Nrem-1)- cumsum.at(s_loop-1);

  int64_t ans= (N < int(cumsum.size())) ? cumsum.at(N)
                                        : cumsum.at(s_loop-1)+ Nloop* sum_cycle+ sum_remain;
  
  cout << ans << endl;
}