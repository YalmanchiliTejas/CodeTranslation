#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
// #define int long long

using namespace std;

typedef int Val_TYPE;
typedef vector<Val_TYPE> Container_TYPE;
typedef priority_queue<Val_TYPE, Container_TYPE> pri_queue;

class Queue: public pri_queue{
public:
    Container_TYPE::iterator begin(){
        return pri_queue::c.begin();
    }
    Container_TYPE::iterator end(){
        return pri_queue::c.end();
    }
}Q;

//v.push_back(123);
//sort(v.begin(), v.end(),greater<int>());
//for(int x : v) {cout << x << endl;}

//for(int x: v) cout << x << endl;
//vector<vector<char>> v(H, vector<char>(W));
// vector<int> v(1000);

long long pow_mod(long long x, long long y, long long MOD){
	long long ret = 1;
	while(y){
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y>>=1;
	}
	return ret;
}

signed main(){
  int N;
  cin>>N;
  int A[N];
  rep(i, N) cin >> A[i];
  int count = 0;
  int flag=1;
  
//   pri_queue<int, vector<int>, greater<int>> q;
  vector<int> q;
  int minimum=1000000009;
  rep(i, N){
    flag=1;
    if(i==0){
      q.push_back(A[i]);
//       minimum = A[i];
      count++;
      continue;
    }
    vector<int>::iterator tmp;
    if(q[0]<A[i]){
      tmp = lower_bound(q.begin(), q.end(), A[i]);
      if((tmp-q.begin())!=0){
        q[tmp-q.begin()-1]=A[i];
      }else{
        q[tmp-q.begin()] = A[i];
      }
//       q.push(A[i]);
      flag=0;
    }
    if(flag){
      tmp = lower_bound(q.begin(), q.end(), A[i]);
      
      if((tmp-q.begin())!=0){
        q.insert(tmp-1, A[i]);
      }else{
        q.insert(tmp, A[i]);
      }

//       sort(q.begin(), q.end(), greater<int>());
//       minimum = A[i];
      count++;
    }
  }
  cout << count << endl;

  return 0;
}
