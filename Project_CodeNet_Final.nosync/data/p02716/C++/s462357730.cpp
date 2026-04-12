#include <bits/stdc++.h>
using namespace std;
#define asc(i,a,n) for (I i=a;i<n;i++)
#define dsc(i,a,n) for (I i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define P auto
typedef vector<long long int> VI;
typedef long long int I;
typedef pair<long long int,long long int> PII;
typedef double D;
typedef set<long long int> OSI;
typedef unordered_set<long long int> USI;
struct node{
  I pre;
  I suf;
  I sum;
  I mxsum;
  I l;
  I r;
};
I rootmax(node tree[],I n,I a[],I m){
  dsc(i,0,n/2){
    I k=(tree[2*i+1].l+tree[2*i+2].r)/2;
    if(k>=m){
      k=0;
    }else{
      k=a[k];
    }
    tree[i].l=tree[2*i+1].l;
    tree[i].r=tree[2*i+2].r;
    tree[i].sum=tree[2*i +1].sum+tree[2*i +2].sum +k;
    tree[i].pre=max(tree[2*i+1].pre,tree[2*i+1].sum+tree[2*i+2].pre+k);
    tree[i].suf=max(tree[2*i+2].suf,tree[2*i+2].sum+tree[2*i+1].suf+k);
    tree[i].mxsum=max(tree[2*i+1].suf+tree[2*i+2].pre+k,max(tree[2*i+1].mxsum,tree[2*i+2].mxsum));
  }
  return tree[0].mxsum;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    I n;
    cin>>n;
    I a[n];
    I sum=0;
    asc(i,0,n){
      cin>>a[i];
      sum+=a[i];
    }
    if(!(n&1)){
      I ev=0;
      asc(i,0,n){
        ev+=a[i];
        i++;
      }
      I mx=0;
      asc(i,3,n){
        if(i&1){
          mx+=a[i];
        }
      }
      mx+=a[0];
      I temp=mx;
      asc(i,3,n-2){
        if(i&1){
          temp-=a[i];
          temp+=a[i-1];
        }
        mx=max(mx,temp);
      }
      mx=max(ev,mx);
      mx=max(sum-ev,mx);
      cout<<mx;
    }else{
      I od=0;
      asc(i,0,n){
        od+=a[i];
        i++;
      }
      I d[n];
      asc(i,0,n){
        if(i%2){
          d[i]=a[i];
        }else{
          d[i]=-a[i];
        }
      }
      I m=n/2;
      m++;
      I sz=pow(2,ceil(log(m)/log(2)));
      node tree[2*sz -1];
      asc(i,0,m){
        tree[sz-1+i].sum=tree[sz-1+i].pre=tree[sz-1+i].suf=tree[sz-1+i].mxsum=d[2*i];
        tree[sz-1+i].l=tree[sz-1+i].r=2*i;
      }
      asc(i,m,sz){
        tree[sz-1+i].sum=tree[sz-1+i].pre=tree[sz-1+i].suf=tree[sz-1+i].mxsum=-1000000001;
        tree[sz-1+i].l=tree[sz-1+i].r=2*i;
      }
      I difsum=rootmax(tree,2*sz-1,d,n);
      cout<<od+difsum;
    }
    return 0;
}