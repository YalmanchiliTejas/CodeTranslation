#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int64_t N;
    cin >> N;
    int64_t sum = 0;
    vector<int64_t> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
        sum += vec[i];
    }
    //回数の下限
    int64_t ans = sum - N*(N-1);
    int64_t cnt = 0;
    if(ans > 0){
      for(int i=0; i<N; i++){
        //全部+であればansだけ増える。結果として、N-1以下になればいい
        vec[i] += ans - (N-1);
        //その時に選ばないといけない回数。一回選ぶと+1がないのとN引かれるからN+1相当
        int64_t x = (vec[i] + N) / (N+1);
        vec[i] -= x*(N+1);
        cnt += x;
      }
    }
  
    if(cnt > ans && ans > 0){
      for(int i=0; i<N; i++){
         vec[i] += cnt - ans;
      }
    }
  
    ans = cnt;
   
   if(ans > 0){
     for(int i=0; i<N; i++){
       vec[i] += N-1;
     }
   }
  
    while(true){
      sort(vec.rbegin(),vec.rend());
      if(vec[0] < N){
        break;
      }
      vec[0] -= N;
      for(int i=1; i<N; i++){
        vec[i]++;
      }
      ans++;
    }
    
    cout << ans << endl;
    
}

