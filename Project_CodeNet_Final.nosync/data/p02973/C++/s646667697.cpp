# include <bits/stdc++.h>
using namespace std;
typedef long long i64;
typedef vector<int> Vi;
typedef pair<int, int> Pii;
# define pb push_back
# define mp make_pair
# define MOD 1000000007
# define INF 1000000000
# define bug puts("H");

const int N = 100000 + 5;

inline int Scan() {
    int x=0;int f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}


int d[N],n,b[N];

int LIS(){
    b[1]=d[1];
    int l,r,mid,len=1;
    for(int i=2;i<=n;i++){
        l=1;
        r=len;
        while(l<=r){
        mid=(l+r)/2;
        if(b[mid]<=d[i]) //if(b[mid]<=d[i]) 改成这样就是最长不下降子序列
        l=mid+1;

        else  r=mid-1;
        }
        b[l]=d[i];
        if(l>len) len++;

    }
    return len;
}
int main ()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>d[i];
        d[i] = 1000000000 - d[i];
    }
    int len=LIS();
    cout<<len;
    return 0;
    return 0;
}
