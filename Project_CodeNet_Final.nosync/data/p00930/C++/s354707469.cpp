#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;

static const int MAX_SIZE = 1 << 20; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

typedef long long Int;
int segMin[2 * MAX_SIZE - 1], segAdd[2 * MAX_SIZE - 1];

//区間[a, b)に値xを加算する.
void add(int a, int b, int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return; //もし交差しない区間であれば終える.
	
	if (a <= l && r <= b){ //もし今みている区間[l, r)が[a, b)に完全に内包されていれば
		segAdd[k] += x;  //区間[l, r)にkを加算する.
		return;
	}
	
	add(a, b, x, k * 2 + 1, l, (l + r) / 2); //子の区間に(必要があれば)xを加算する.
	add(a, b, x, k * 2 + 2, (l + r) / 2, r); //〃

	//親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である.一様に加算される値は更新しなくて良い.
	segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

int getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return (INT_MAX);
	
	if (a <= l && r <= b) return (segMin[k] + segAdd[k]); //完全に内包されていれば,その区間の最小値を返す.
	
	int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2); //子の区間の最小値を求める.
	int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r); //子の区間の最小値を求める
	
	return (min(left, right) + segAdd[k]); //親の区間の最小値は, 子の区間の最小値 + 自分に一様に加算されている値 である (大切なので2回書きました!!)
	
}


int main(){
    int n,q;cin >> n >> q;
    string s;cin >> s;
    set<int> sb;
    int sum=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            sum++;
        }
        else{
            sum--;
            sb.insert(i);
        }
        add(i,i+1,sum);
    }
    for(int i=0;i<q;i++){
        int t;cin >> t;
        t--;
        if(s[t]=='('){
            add(t,n,-2);
            sb.insert(t);
            auto p=sb.begin();
            s[t]=')';
            s[*p]='(';
            sb.erase(*p);
            add(*p,n,2);
            cout << *p+1 << endl;
        }
        else{
            add(t,n,2);
            sb.erase(t);
            s[t]='(';
            int l=0,r=t;
            while(abs(r-l)>1){
                int m=(l+r)/2;
                if(getMin(m,n)>=2) r=m;
                else l=m;
            }
            s[r]=')';
            add(r,n,-2);
            sb.insert(r);
            cout << r+1 << endl;
        }
    }
    return 0;
}

