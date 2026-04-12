#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N){
    cin >> a[i];
  }
  sort(all(a));
  int head = 0,tail = N-2;
  deque<int> bigA;
  bigA.push_back(a[N-1]);
  int i = 0;
  while(head <= tail ){
    if(i%2 == 1){
      bigA.push_front(a[tail]);
      tail--;
      if(head > tail) break;
      bigA.push_back(a[tail]);
      tail--;
    }else{
      bigA.push_front(a[head]);
      head++;
      if(head > tail) break;
      bigA.push_back(a[head]);
      head++;
    }
    i++;
  }

   int current; long long score = 0;
   int prev = bigA.front();
  bigA.pop_front();
  while(bigA.empty() == false){
    current = bigA.front();
    bigA.pop_front();
    score += abs(prev - current);
    prev = current;
    //cout << "null " << bigA.size() << endl;
  }


  // min
  head = 1; tail = N-1;
  deque<int> smallA;
  smallA.push_back(a[0]);
  i = 0;
  while(head <= tail){
    if(i%2 == 0){
      smallA.push_front(a[tail]);
      tail--;
      if(head > tail) break;
      smallA.push_back(a[tail]);
      tail--;
    }else{
      smallA.push_front(a[head]);
      head++;
      if(head > tail) break;
      smallA.push_back(a[head]);
      head++;
    }
    //cout << smallA.front() << ' ' << smallA.back() << endl;
    i++;
  }

  long long score2 = 0;
  //cout << smallA.size() << endl;
  prev = smallA.front();
  smallA.pop_front();
  //cout << prev << ' ';
  while(smallA.empty() == false){
    //cout << current << ' ';
    current = smallA.front();
    smallA.pop_front();
    score2 += abs(prev - current);
    prev = current;
  }
  //cout << endl;
  cout << max(score , score2) << endl;
  return 0;
}
