#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
long long inf=(long long)1E17;
#define i_7 (long long)(1E9+7)
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
using namespace std;
long long gcd(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd(b,a%b);
  }
}
 
long long lcm(long long x, long long y){
  return (x/gcd(x,y))*y;
}
 
class UnionFind {
    public:
    //各頂点の親の番号を格納する。その頂点自身が親だった場合は-(その集合のサイズ)を入れる。
    vector<int> Parent;
    
    //クラスを作るときは、Parentの値を全て-1にする。
    //以下のようにすると全てバラバラの頂点として解釈できる。
    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }
    
    //Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }
    
    //自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//先祖をrootで取っておきたい。
    }
    
    //AとBをくっ付ける
    bool connect(int A, int B) {
        //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }
        
        //大きい方(A)に小さいほう(B)をくっ付けたい
        //大小が逆だったらAとBをひっくり返す。
        if (size(A) < size(B)) swap(A, B);
        
        //Aのサイズを更新する
        Parent[A] += Parent[B];
        //Bの親をAに変更する
        Parent[B] = A;
        
        return true;
    }
};
 
int main(){
  int n;
  string s;
  cin>>n;
  cin>>s;
  string t="";
  t += 'S';
  t += 'S';
  REP(i,n){
    if(i==0 || i==1){
      continue;
    }
    if(t[i-1]=='S' && s[i-1]=='o'){
      t += t[i-2];
    }else if(t[i-1]=='S' && s[i-1]=='x'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else if(t[i-1]=='W' && s[i-1]=='o'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else{
      t += t[i-2];
    }
  }
  int cnt=0;
  if(t[n-1]=='S' && s[n-1]=='o'){
    if(t[n-2]==t[0]){
      cnt++;
    }
  }else if(t[n-1]=='S' && s[n-1]=='x'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else if(t[n-1]=='W' && s[n-1]=='o'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else{
    if(t[n-2]==t[0]){
      cnt++;
    }
  }
  if(t[0]=='S' && s[0]=='o'){
    if(t[n-1]==t[1]){
      cnt++;
    }
  }else if(t[0]=='S' && s[0]=='x'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else if(t[0]=='W' && s[0]=='o'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else{
    if(t[n-1]==t[1]){
      cnt++;
    }
  }
  if(cnt==2){
    cout<<t<<endl;
    return 0;
  }else{
    t="";
    cnt=0;
  }
  
  t += 'S';
  t += 'W';
  REP(i,n){
    if(i==0 || i==1){
      continue;
    }
    if(t[i-1]=='S' && s[i-1]=='o'){
      t += t[i-2];
    }else if(t[i-1]=='S' && s[i-1]=='x'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else if(t[i-1]=='W' && s[i-1]=='o'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else{
      t += t[i-2];
    }
  }
  
  if(t[n-1]=='S' && s[n-1]=='o'){
    if(t[n-2]==t[0]){
      cnt++;
    }
  }else if(t[n-1]=='S' && s[n-1]=='x'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else if(t[n-1]=='W' && s[n-1]=='o'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else{
    if(t[n-2]==t[0]){
      cnt++;
    }
  }
  if(t[0]=='S' && s[0]=='o'){
    if(t[n-1]==t[1]){
      cnt++;
    }
  }else if(t[0]=='S' && s[0]=='x'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else if(t[0]=='W' && s[0]=='o'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else{
    if(t[n-1]==t[1]){
      cnt++;
    }
  }
  if(cnt==2){
    cout<<t<<endl;
    return 0;
  }else{
    t="";
    cnt=0;
  }
  
  t += 'W';
  t += 'S';
  REP(i,n){
    if(i==0 || i==1){
      continue;
    }
    if(t[i-1]=='S' && s[i-1]=='o'){
      t += t[i-2];
    }else if(t[i-1]=='S' && s[i-1]=='x'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else if(t[i-1]=='W' && s[i-1]=='o'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else{
      t += t[i-2];
    }
  }
  
  if(t[n-1]=='S' && s[n-1]=='o'){
    if(t[n-2]==t[0]){
      cnt++;
    }
  }else if(t[n-1]=='S' && s[n-1]=='x'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else if(t[n-1]=='W' && s[n-1]=='o'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else{
    if(t[n-2]==t[0]){
      cnt++;
    }
  }
  if(t[0]=='S' && s[0]=='o'){
    if(t[n-1]==t[1]){
      cnt++;
    }
  }else if(t[0]=='S' && s[0]=='x'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else if(t[0]=='W' && s[0]=='o'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else{
    if(t[n-1]==t[1]){
      cnt++;
    }
  }
  if(cnt==2){
    cout<<t<<endl;
    return 0;
  }else{
    t="";
    cnt=0;
  }
  
  t += 'W';
  t += 'W';
  REP(i,n){
    if(i==0 || i==1){
      continue;
    }
    if(t[i-1]=='S' && s[i-1]=='o'){
      t += t[i-2];
    }else if(t[i-1]=='S' && s[i-1]=='x'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else if(t[i-1]=='W' && s[i-1]=='o'){
      if(t[i-2]=='S'){
        t += 'W';
      }else{
        t += 'S';
      }
    }else{
      t += t[i-2];
    }
  }
  
  if(t[n-1]=='S' && s[n-1]=='o'){
    if(t[n-2]==t[0]){
      cnt++;
    }
  }else if(t[n-1]=='S' && s[n-1]=='x'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else if(t[n-1]=='W' && s[n-1]=='o'){
    if(t[n-2]!=t[0]){
      cnt++;
    }
  }else{
    if(t[n-2]==t[0]){
      cnt++;
    }
  }
  if(t[0]=='S' && s[0]=='o'){
    if(t[n-1]==t[1]){
      cnt++;
    }
  }else if(t[0]=='S' && s[0]=='x'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else if(t[0]=='W' && s[0]=='o'){
    if(t[n-1]!=t[1]){
      cnt++;
    }
  }else{
    if(t[n-1]==t[1]){
      cnt++;
    }
  }
  if(cnt==2){
    cout<<t<<endl;
    return 0;
  }else{
    t="";
    cnt=0;
  }
  
  cout<<-1<<endl;
  return 0;
}
