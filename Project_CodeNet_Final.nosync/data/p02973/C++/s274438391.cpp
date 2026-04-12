#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long long MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
ll gcd(ll a,ll b){//aとbの最大公約数を返す//計算量は0(log(max(a,b))
  if(a%b==0){return b;}
  else{return gcd(b,a%b);}
}
ll lcm(ll a,ll b){//aとbの最小公倍数を返す//計算量は0(log(max(a,b))
  return a*b/gcd(a,b);
}
ll pow(ll x,ll y){//x^yを返す//計算量は0(log(y))
  ll tmp=x,res=1;
  while(y){
    if(y%2){res=res*tmp%MOD;}
    y>>=1;
    tmp=tmp*tmp%MOD;
  }
  return res;
}
ll nature(ll a){//絶対値を返す
  if(a>=0){return(a);}
  else{return(-1*a);}
}
ll prime(ll a){//素数なら1を返す//計算量は0(sqrt(a))
  if(a==2){return 1;}
  else if(a%2==0 || a==1){return 0;}
  for(ll i=3;i*i<=a;i+=2){if(a%i==0){return 0;}}
  return 1;
}
vector<int> Z;
void z_algorithm(string str){//計算量はO(str.size())
  Z.resize(str.size());
  Z.at(0)=str.size();
  int m=1,n=0;
  while(m<(int)str.size()){
    while(m+n<(int)str.size()&&str.at(n)==str.at(m+n)){n++;}
    Z.at(m)=n;
    if(n==0){
      m++;
      continue;
    }
    int k=1;
    while(k+Z.at(k)<n){
      Z.at(m+k)=Z.at(k);
      k++;
    }
    m+=k;
    n-=k;
  }
}
template <typename T>
struct BIT{
    //区間加算O(log(N))
    //区間シグマ計算O(log(N))
    //単点加算O(log(N))
    //単点計算O(log(N))
    int n;//元の数列のサイズ
    vector<T> bit[2];//データ収納用
    vector<T> for_bubblesort;
    void init(int n_){
        n=n_+1;
        for(int j=0;j<2;j++){
          bit[j].assign(n,0);
        }
    }
    void add_sub(int p,int i,T x){
        for(int j=i;j<n;j+=j&-j){
            bit[p][j]+=x;
        }
    }
    void add(int l,int r,T x){//[l,r]に加算
        add_sub(0,l,-x*(l-1));
        add_sub(0,r+1,x*r);
        add_sub(1,l,x);
        add_sub(1,r+1,-x);
    }
    T sum_sub(int p,int i){
        T s(0);
        for (int j=i;j>0;j-=j&-j){
            s+=bit[p][j];
        }
        return s;
    }
    T sum(int i,int j){//[i,j]のΣを計算
        return sum_sub(0,j)+sum_sub(1,j)*j-sum_sub(0,i-1)-sum_sub(1,i-1)*(i-1);
    }
    //ここから二分探索関連
    T binary_search_sum1(int key){//a_1+a_2+...+a_x>=keyとなるような最小のxを求める(ただしa_i>=0)
    //key以上の値
            if(key<=0){
                return 0;
            }
            else{
                int x=0,r=1;
                while(r<n){
                    r=r<<1;
                }
                for(int length=r;length>0;length=length>>1){//長さlenは1段下るごとに半分に
                    if(x+length<n&&sum(x+1,x+length)<key){//採用するとき
                        key-=sum(x+1,x+length);
                        x+=length;
                    }
                }
                return x+1;
            }
    }
    T binary_search_sum2(int key){//a_1+a_2+...+a_x<=keyとなるような最大のxを求める(ただしa_i>=0)
    //key以下の値
            key++;
            if(key<=0){
                return 0;
            }
            else{
                int x=0,r=1;
                while(r<n){
                    r=r<<1;
                }
                for(int length=r;length>0;length=length>>1){//長さlenは1段下るごとに半分に
                    if(x+length<n&&sum(x+1,x+length)<key){//採用するとき
                        key-=sum(x+1,x+length);
                        x+=length;
                    }
                }
                return x;
            }
    }
    //二分探索終わり
    //ここからはbubblesort関連
    void init_bubblesort(int n_){
        n=n_+1;
        for_bubblesort.assign(n,0);
    }
    void add_bubblesort(int i,T x) {
        for(int j=i;j<n;j+=j&-j){
            for_bubblesort[j]+=x;
        }
    }
    T calculate_bubblesort(int i) {
        T s=0;
        for(int j=i;j>0;j-=j&-j){
            s+=for_bubblesort[j];
        }
        for(int j=i-1;j>0;j-=j&-j){
            s-=for_bubblesort[j];
        }
        return s;
    }
    T bubblesort(){
        //bitとfor_bubblesort両方initしてadd_for_bubblesortしてから使う
        int answer_for_bubblesort=0;
        int sum_for_bubblesort;
        for(int i=1;i<=n-1;i++){
            sum_for_bubblesort=calculate_bubblesort(i);
            answer_for_bubblesort+=i-sum(1,sum_for_bubblesort)-1;
            add(sum_for_bubblesort,sum_for_bubblesort,1);
        }
        return answer_for_bubblesort;
    }
    //bubblesort関連終わり
    /*
    使い方
    BIT<int> rock;
    rock.init(N);    Nは加算などの操作を行う配列のサイズ
    ...(その後は適当に)
    */
};
template<typename T>
struct BIT2D{
    //単点に値たすO(1)
    //[1,h][1,w]の総和O(log(h)*log(w))
    //[h,hh][w,ww]の値の総和O(4*log(max(h,w,hh,ww)))
    int H,W;
    vector<vector<T>> bit;
    void init(int H_,int W_){
        H=H_+1;
        W=W_+1;
        bit.assign(H,vector<T>(W,0));
    }
    void add(int h,int w,T x){//(h,w)にxを足す0(log(h)*log(w))  (区間サイズnの場合O(N))
        for(int i=h;i<H;i+=i&-i){
            for(int j=w;j<W;j+=j&-j){
                bit[i][j]+=x;
            }
        }
    }
    T sum(int h,int w){//[1,h][1,w]の総和O(log(h)*log(w))
        T s=0;
        for(int i=h;i>0;i-=i&-i){
            for(int j=w;j>0;j-=j&-j){
                s+=bit[i][j];
            }
        }
        return s;
    }
    T partsum(int h,int w,int hh,int ww){//[h,hh][w,ww]の総和O(log(max(h,w,hh,ww)))
        //前処理でsumを計算しておけば計算量減らせるかも
        return sum(hh,ww)+sum(h-1,w-1)-sum(hh,w-1)-sum(h-1,ww);
    }
};
int main(){
    int N;
    cin>>N;
    vector<int> A(0);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        if(i==0){A.push_back(a);}
        else{
            int left=0;
            int right=A.size()-1;
            int ans=N+2;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(A.at(mid)<a){
                    ans=min(ans,mid);
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            if(ans==N+2){
                int memo=A.size();
                A.insert(A.begin()+memo,a);
            }
            else{
                A.at(ans)=a;
            }
        }
    }
    cout<<A.size()<<endl;
}