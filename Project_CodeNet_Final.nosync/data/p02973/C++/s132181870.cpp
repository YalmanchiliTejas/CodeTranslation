#include "bits/stdc++.h"
using namespace std;
#define REP(i, n) for(ll i = 0;i < n;i++)
#define ll long long
#define MOD 1000000007


//2分岐探索
vector<int> v(100001);

int nibutan(int n,int k){
    int mid=n-1;
    int end=n-1;
    int srt=0;
    int  mmid;
    int res;
    //2分岐
    for(int j=0;;j++){
      mmid=mid;
      res=v[mid];
      if (res<k){
        end=mid;
        mid=srt+(mid-srt)/2;
      }else{
        srt=mid;
        mid=mid+(end-mid)/2;
      }
      if (mmid==mid)break;
      //if (mid==0)break;
    }
    return mid;
}



int main(){
  int n=0;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin>>a[i];
  REP(i,100001) v[i]=-1;
  int w=1,idx;
  v[0]=a[0];

    for(int i=1;i<n;i++){
        idx=nibutan(w+1,a[i])+1;
        if (v[idx-1]<a[i])idx--;
        //cout<<idx<<" "<<v[idx]<<endl;
        for(int j=idx;j>=0;j--){
            if (v[j]<a[i]){
                if (v[j]==-1)w++;
                v[j]=a[i];
                break;
            }
        }
    }
        

    cout<<w<<endl;
  return 0;
}