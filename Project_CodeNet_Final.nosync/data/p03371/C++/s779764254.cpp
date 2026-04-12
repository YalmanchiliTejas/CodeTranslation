#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i < (int)(b); ++i)
#define endl "\n"
typedef long long ll;
const double pi=3.14159265358979323846;
int ctoi(const char c) {
    if ('0' <= c && c <= '9') return (c - '0');
    return -1;
}
vector<int> input(int n) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    return vec;
}
void output(vector<int> vec) {
    for (int i = 0; i < int(vec.size()); i++) {
        cout << vec[i] << " ";
    }
    return;
}
vector<vector<int>> input(int n, int m) {
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table. at(i).at(j);
        }
    }
    return table;
}
void output(vector<vector<int>> table) {
    for (int i = 0; i < int(table.size()); i++) {
        for (int j = 0; j < int(table.at(0).size()); j++) {
            cout << table.at(i).at(j) << " ";
        }
        cout << endl;
    }
}
long long perm(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long perm = 1;
    for (int i = n; i > n - r; i--) {
        perm *= i;
    }
    return perm;
}
long long comb(int n, int r) {
    if (n < r) {
        cout << "error" << endl;
        return 0;
    }
    long long comb = perm(n,r);
    for (int i = r; i > 0; i--) {
        comb /= i;
    }
    return comb;
}
long long homo(int n, int r) {
    return comb(n + r - 1, n - 1);
}
long long fact(int n) {
    long long fact = 1;
    for (int i = n; i > 0; i--) {
        fact *= i;
    }
    return fact;
}
int gcd(int a, int b){
    if (a % b == 0){
        return(b);
    }else{
        return(gcd(b, a % b));
    }
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
bool isprime(int n){
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
 
    for (int i = 3; i <= sqrt(n); i += 2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
vector<long long> divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
 
    /*long long N;
    cin >> N;
    vector<long long> res = divisors(N);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;*/
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
void Yes(bool f) {
    if (f) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
void YES(bool f) {
    if (f) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
bool leapyear(int y){
  //閏年かどうかを判定
  if(y%4==0){
    if(y%100==0){
      if(y%400==0){
        return true;
      }else{
        return false;
      }
    }else{
      return true;
    }
  }else{
    return false;
  }
}
tuple<int,int,int> dayplus(int y, int m,int d){
  //次の日を返す
  //31日まである月
  if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
    if(d!=31){
      d++;
      return make_tuple(y,m,d);
    }else{
      d=1;
      if(m==12){
        m=1;
        y++;
        return make_tuple(y,m,d);
      }else{
        m++;
        return make_tuple(y,m,d);
      }
    }
  }
  //30日まである月
  else if(m==4||m==6||m==9||m==11){
    if(d!=30){
      d++;
      return make_tuple(y,m,d);
    }else{
      d=1;
      m++;
      return make_tuple(y,m,d);
    }
  }
  //2月
  else{
    //閏年の場合
    if(leapyear(y)){
      if(d!=29){
        d++;
        return make_tuple(y,m,d);
      }else{
        d=1;
        m++;
        return make_tuple(y,m,d);
      }
    }
    //閏年ではない場合
    else{
      if(d!=28){
        d++;
        return make_tuple(y,m,d);
      }else{
        d=1;
        m++;
        return make_tuple(y,m,d);
      }
    }
  }
}
tuple<int,int,int> monplus(int y,int m,int d){
  //月を一つ先に、日を一日にする
  d=1;
  if(m==12){
    m=1;
    y++;
    return make_tuple(y,m,d);
  }else{
    m++;
    return make_tuple(y,m,d);
  }
}
bool in(vector<int> a,int x){
  if(find(a.begin(),a.end(),x)!=a.end()){
    return true;
  }else{
    return false;
  }
}
int count_bool(vector<bool> flag){
  int count=0;
  for(int i=0;i<int(flag.size());i++){
    if(flag[i]){
      count++;
    }
  }
  return count;
}
 
int main() {
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  
  int d=min(x,y);
  int e=max(x-d,y-d);
  
  ll ans=0;
  
  if(c*2>a+b){
    ans+=(a+b)*d;
  }else{
    ans+=c*2*d;
  }
  
  if(x>y){
    if(a>c*2){
      ans+=c*2*e;
    }else{
      ans+=a*e;
    }
  }else{
    if(b>c*2){
      ans+=c*2*e;
    }else{
      ans+=b*e;
    }
  }
  
  cout << ans << endl;
  
}