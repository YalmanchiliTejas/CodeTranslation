#include <bits/stdc++.h>
#include <stdio.h>
#include <cassert>
using namespace std;
typedef long long lo;
typedef pair<lo,lo> ll;//pair
typedef vector<lo> vl;  //vector of long
typedef vector<ll > vll;   //vector of pair
typedef priority_queue<lo>p_q;
typedef vector< vl > vvl;  //vector of vectors
#define X first
#define Y second
#define mp(a,b) make_pair((a),(b))
#define REP(a,b) for(lo i=(a);i<(lo)b;i++)//no need to declare variable i
#define REPE(a,b,c,d) REP(a,b)for(lo j=(c);j<(lo)d;j++)//no need to declare vaiables i,j
#define REPV(a,b,c) for((a)=b;(a)<(c);(a)++)//a is the variable
#define IREP(a,b) for(lo i=(a);i>=(b);i--)
#define IREPV(a,b,c) for((a)=b;(a)>=(c);(a)--)
#define all(v) (v).begin(),(v).end()
#define TRV(a) for(auto i : a)
#define INF 30000000000
#define MOD 1000000007
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define pb(a) push_back((a))
/*
using namespace __gnu_pbds;
order statistic tree
typedef
tree<
  lo,
    null_type,
  less_equal<lo>,
  rb_tree_tag,
  // This policy updates nodes' metadata for order statistics.
  tree_order_statistics_node_update>
ordered_set*/

/*
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void sprint( lo a){
	if(a<0){
		pc('-');
		a = abs(a);
	}
    lo i=0;
    char S[20];
    if(a==0)pc('0');
    if(a<0){
        pc('-');
        a*=-1;
    }
    while(a>0){
        S[i++]=a%10+'0';
        a=a/10;
    }
    --i;
    while(i>=0)
    pc(S[i--]);
    pc(' ');
}
inline void lprint( lo a){
	if(a<0){
		pc('-');
		a = abs(a);
	}
    lo i=0;
    char S[20];
    if(a==0)pc('0');
    if(a<0){
        pc('-');
        a*=-1;
    }
    while(a>0){
        S[i++]=a%10+'0';
        a=a/10;
    }
    --i;
    while(i>=0)
    pc(S[i--]);
    pc('\n');
}
inline lo uscan(){
    unsigned lo n=0,c=gc();
    while(c<'0'||c>'9')c=gc();
    while(c<='9'&&c>='0'){
	    n=n*10+c-'0';
	    c=gc();
	}
    return n;
}*/
template<typename T> ostream& operator<< ( ostream &o,vector<T> v ) {
    if ( v.size() >0 )o<<v[0];
    for ( unsigned   i=1; i<v.size(); i++ )o<<" "<<v[i];
    return o<<endl;
}
template<typename U,typename V> ostream& operator<< ( ostream &o,pair<U,V> p ) {
    return o<<"("<<p.first<<", "<<p.second<<") ";
}
template<typename T> istream& operator>> ( istream &in,vector<T> &v ) {
    for ( unsigned   i=0; i<v.size(); i++ )in>>v[i];
    return in;
}
template<typename T> istream& operator>> ( istream &in,pair <T,T> &p ) {
    in>>p.X;
    in>>p.Y;
    return in;
}
/*
///////////////////////////////////////////////////////////////////////////////////////////////LCA IN O(1)
const lo MAXN = INF;
const lo MAXLIST = INF * 2;
const lo LOG_MAXLIST = 18;
const lo SQRT_MAXLIST = 447;
const lo MAXBLOCKS = MAXLIST / ((LOG_MAXLIST + 1) / 2) + 1;

lo root;
vl g [MAXN];
lo h [MAXN]; // vertex height
vl a; // dfs list
lo a_pos [MAXN]; // positions in dfs list
lo block; // block size = 0.5 log A.size ()
lo bt [MAXBLOCKS] [LOG_MAXLIST + 1]; // sparse table on blocks (relative minimum positions in blocks)
lo bhash [MAXBLOCKS]; // block hashes
lo brmq [SQRT_MAXLIST] [LOG_MAXLIST / 2] [LOG_MAXLIST / 2]; // rmq inside each block, indexed by block hash
lo log20 [2 * MAXN]; // precalced logarithms (floored values)

// walk graph
void dfs (lo v,lo curh) {
	h [v] = curh;
	a_pos [v] = (lo)a.size ();
	a.push_back (v);
	for (size_t i = 0; i <g [v] .size (); ++ i)
		if (h [g [v] [i]] == -1) {
			dfs (g [v] [i], curh + 1);
			a.push_back (v);
		}
}

lo log (lo n) {
	lo res = 1;
	while (1 << res <n) ++ res;
	return res;
}

// compares two indices in a
inline lo min_h (lo i,lo j) {
	return h [a[i]] <h[a[j]]? i: j;
}

// O (N) preprocessing
void build_lca () {
	lo sz = (lo) a.size ();
	block = (log(sz) + 1) / 2;
	lo blocks = (sz+block-1) / block ;

	// precalc in each block and build sparse table
	memset (bt, 255, sizeof bt);
	for (lo i = 0, bl = 0, j = 0; i <sz; ++ i, ++ j) {
		if (j == block)
			j = 0, ++ bl;
		if (bt [bl] [0] == -1 || min_h (i, bt [bl] [0]) == i)
			bt [bl] [0] = i;
	}
	for (lo j = 1; j <= log (sz); ++ j)
		for (lo i = 0; i <blocks; ++ i) {
			lo ni = i + (1 << (j-1));
			if(ni >= blocks)bt[i][j] = bt [i] [j-1];
			else bt[i][j] = min_h (bt [i] [j-1], bt [ni] [j-1]);
		}

	// calc hashes of blocks
	memset (bhash, 0, sizeof bhash);
	for (lo i = 0, bl = 0, j = 0; i <sz || j <block; ++ i, ++ j) {
		if (j == block)
			j = 0, ++ bl;
		if (j> 0 && (i >= sz || min_h (i-1, i) == i-1))
			bhash [bl] += 1 << (j-1);
	}

	// precalc RMQ inside each unique block
	memset (brmq, 255, sizeof brmq);
	for (lo i = 0; i <blocks; ++ i) {
		lo id = bhash [i];
		if (brmq [id] [0] [0]!= -1) continue;
		for (lo l = 0; l <block; ++ l) {
			brmq [id] [l] [l] = l;
			for (lo r = l + 1; r <block; ++ r) {
				brmq [id] [l] [r] = brmq [id] [l] [r-1];
				if (i * block + r <sz)
					brmq [id] [l] [r] =
						min_h (i * block + brmq [id] [l] [r], i * block + r) - i * block;
			}
		}
	}

	// precalc logarithms
	for (lo i = 0, j = 0; i <sz; ++ i) {
		if (1 << (j + 1) <= i) ++ j;
		log20 [i] = j;
	}
}

// answers RMQ in block #bl [l; r] in O (1)
inline lo lca_in_block (lo bl, lo l, lo r) {
	return brmq [bhash [bl]] [l] [r] + bl * block;
}

// answers LCA in O (1)
lo lca (lo v1, lo v2) {
	lo l = a_pos [v1], r = a_pos [v2];
	if (l> r) swap (l, r);
	lo bl = l / block, br = r / block;
	if (bl == br)
		return a [lca_in_block (bl, l% block, r% block)];
	lo ans1 = lca_in_block (bl, l% block, block-1);
	lo ans2 = lca_in_block (br, 0, r% block);
	lo ans = min_h (ans1, ans2);
	if (bl <br - 1) {
        lo pw2 = log20 [br-bl-1];
		lo ans3 = bt [bl + 1] [pw2];
		lo ans4 = bt [br- (1 << pw2)] [pw2];
		ans = min_h (ans, min_h (ans3, ans4));
	}
	return a [ans];
}
*/
/*
/////////////////////////////////////////////////////////////////////SEGMENT TREE
void build(lo node,lo start , lo end){
	if(start == end){
		tree[node] = a[node];
	}
	else{
		lo mid = (start +end) / 2;
		build( 2 * node + 1 , start , mid);
		build(2*node + 2, mid+1 ,end);
		tree[node] = tree[node * 2 + 1] + tree[node*2+2];
		return;
	}
}
void update(lo node, lo start, lo end, lo l, lo r, lo val){
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end){
            lazy[node*2+1] += lazy[node];                  // Mark child as lazy
            lazy[node*2+2] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)return;
    if(start >= l and end <= r){
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end){
            // Not leaf node
            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    lo mid = (start + end) / 2;
    update(node*2 + 1, start, mid, l, r, val);        // Updating left child
    update(node*2 + 2, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2 +1] + tree[node*2+2];        // Updating root with max value
}
lo queryRange(lo node, lo start, lo end, lo l, lo r){
    if(start > end or start > r or end < l)return 0;         // Out of range
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end){
            lazy[node*2+1] += lazy[node];         // Mark child as lazy
            lazy[node*2+2] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)return tree[node];
    lo mid = (start + end) / 2;
    lo p1 = queryRange(node*2 + 1, start, mid, l, r);         // Query left child
    lo p2 = queryRange(node*2 + 2, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
*/
/*
///////////////////////////////////////////////////////////Z_FUNCTION
vl z_function (string s) {
	lo n = (lo) s.length();
	vl z (n);
	for (lo i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])++z[i];
		if (i+z[i]-1 > r)l = i,  r = i+z[i]-1;
	}
	return z;
}
*/
/*
////////////////////////////////////////////////////////MATH
lo gcd(lo a,lo b){
	if(b==0)return a;
	return gcd(b,a%b);
}
lo power(lo base, lo exp , lo m) {
    lo res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%m;
       base=(base*base)%m;
       exp/=2;
    }
    return res%m;
}
lo inv(lo a, lo m){
    lo m0 = m, t, q;
    lo x0 = 0, x1 = 1;
    if (m == 1)return 0;
    while (a > 1){
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)x1 += m0;
    return x1;
}
*/
/*
////////////////////////////////////////////////////////////nCr
lo power(lo base ,lo exp){
	lo res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
lo factor_power(lo n,lo p){
    lo res=0;
    while(n>0){
        n/=p;
        res+=n;
    }
    return res;
}
lo nCr3(lo n,lo k,lo p,lo e){
    lo pe=power(p,e);
    lo r=n-k;
    vl fact_pe;
    fact_pe.pb(1);
    lo acc=1;
    REP(1,pe){
        if(i%p!=0)acc=(acc*i)%pe;
        fact_pe.pb(acc);
    }
    lo top,bottom;
    top=bottom=1;
    lo is_neg=0;
    lo digits=0;
    while(n>0){
        if(acc!=1)if(digits>=e){
            is_neg^=(n&1);
            is_neg^=(r&1);
            is_neg^=(k&1);
        }
        top = (top * fact_pe[n % pe]) % pe;
        bottom = (bottom * fact_pe[r % pe]) % pe;
        bottom = (bottom * fact_pe[k % pe]) % pe;
        n /= p;
        r /= p;
        k /= p;
        digits++;
    }
    lo res=(top*inv(bottom,pe))%pe;
    if(p!=2 or e<3){
        if(is_neg)res=pe-res;
    }
    return res;
}
lo nCr2(lo n,lo k,lo p,lo e){
    lo r=n-k;
    lo prime_part=factor_power(n,p);
    prime_part-=factor_power(k,p);
    prime_part-=factor_power(r,p);
    if(prime_part>=e)return 0;
    lo modpow=e-prime_part;
    r=nCr3(n,k,p,modpow);
    return (power(p,prime_part)*r)%power(p,e);
}
lo nCr(lo n,lo r,lo m){
    vll factors;
    lo y=m;
    for(lo i=2;i*i<=m;i++){
        if(y%i==0){
            lo x=0;
            while(y%i==0){
                y/=i;
                x++;
            }
            factors.pb(mp(i,x));
        }
    }
    if(y>1)factors.pb(mp(y,1));
    //REP(0,factors.size())cout<<factors[i]<<" ";
    vll result;
    REP(0,factors.size()){
        lo x=nCr2(n,r,factors[i].first,factors[i].second);
        result.pb(mp(x,power(factors[i].X,factors[i].Y)));
    }
    lo prod = 1;
    REP(0,result.size())prod*=result[i].second;
    lo ans = 0;
    // Apply above formula
    REP(0,result.size()){
        lo pp = prod / result[i].second;
        ans += result[i].first * inv(pp, result[i].second) * pp;
    }
    return ans % prod;
}
*/
/*
///////////////////////////////////////////////////////////////////////////TRIE
struct node{
    map<char,node*> child;
}*groot;
set<string> ans;
void insert(const string & a){
    node *root=groot;
    lo x=0;
    while(root!=NULL){
        auto i=(root->child).find(a[x]);
        if(i==(root->child).end())break;
        root=i->second;
        x++;
    }
    REP(x,a.length()){
        node *ptr=new node;
        root->child[a[x]]=ptr;
        root=ptr;
        x++;
        ptr=NULL;
    }
    //root->child[a[a.length()-1]]=NULL;
}
void check(const string & a){
    node *root=groot;
    lo x=0;
    bool found=false;
    string temp;
    while(root!=NULL and x<a.length()){
        auto i=(root->child).find(a[x]);
        if(i==(root->child).end())break;
        temp+=a[x];
        x++;
        root=i->second;
    }
    if(x==a.length())res=false;
    temp+=a[x];
    ans.insert(temp);
}
void print(node *ptr){
    if(ptr!=NULL)TRV(ptr->child){
        cout<<(it->first);
        print(it->second);
    }
}
*/

/*
lo fast_exp(lo base, lo exp , lo m) {
    lo res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%m;
       base=(base*base)%m;
       exp/=2;
    }
    return res%m;
}
lo inv(lo a, lo m)
{
    lo m0 = m, t, q;
    lo x0 = 0, x1 = 1;

    if (m == 1)
       return 0;
    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}*/

/*
/////////////////////////////////////////////////////////////////////////union find
vector<lo> pset;
void initSet(lo _size){REP(0,_size)pset[i]=i;}
void initSet(lo _size) { pset.resize(_size); REP ( 0, _size - 1) pset[i] = i; }
lo findSet(lo i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(lo i, lo j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(lo i, lo j) { return findSet(i) == findSet(j); }
}
*/

/////////////////////////////////////////////////////////////////////////sieve
lo _sieve_size; // ll is defined as: typedef long long ll;
bitset<500> bs; // 10^7 + small extra bits should be enough for most prime-related problems
vl primes; // compact list of primes in form of vector<lo>
void sieve(lo upperbound) { // create list of primes in [0 .. upperbound]
    _sieve_size = upperbound + 1; // add 1 to include upperbound
    bs.reset(); bs.flip(); // set all numbers to 1
    bs.set(0, false); bs.set(1, false); // except index 0 and 1
    for (lo i = 2; i <= _sieve_size; i++) if (bs.test((size_t)i)) {
        for (lo j = i * i; j <= _sieve_size; j += i) bs.set((size_t)j, false);
        primes.push_back((lo)i);
    }
}
/*
//////////////////////////////////////////////////////////////////////////suffix array lcp
struct entry {
        lo nr[2], p;
};
vl cont(60000);
vector<entry> output(60000);

void cont_sort(const vector<entry > & L , lo index){
    // The output character array that will have sorted arr

    // Create a cont array to store cont of inidividul
    // characters and initialize cont array as 0
    lo i;
    fill(all(cont),lo(0));
    // Store cont of each character
    for(i = 0; i<L.size(); ++i){
        ++cont[L[i].nr[index]+1];
    }
    // Change cont[i] so that cont[i] now contains actual
    // position of this character in output array
    for (i = 1; i <60000; ++i)cont[i] += cont[i-1];

    // Build the output character array
    for (i=L.size()-1;i>=0; --i){
        output[cont[L[i].nr[index]+1]-1] = L[i];
        --cont[L[i].nr[index]+1];
    }
    // Copy the output array to arr, so that arr now
    // contains sorted characters
}
pair<vl,vl> suffix_lcp_array(string A){
    lo n=A.length();
    vl current(n);
    vl prev(n);
    vector <entry> L(n);
    lo i, stp, cnt;
    REP(0,n)prev[i]=int(A[i]);
    for (stp = 1, cnt = 1; cnt >> 1 < n; stp ++, cnt <<= 1) {
        for (i = 0; i < n; i ++){
            L[i].nr[0] = prev[i];
            L[i].nr[1] = i + cnt < n ? prev[i + cnt] : -1;
            L[i].p = i;
        }
        //sort(all(L),[](const entry & a, const entry & b){
        //    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
        //});
        cont_sort(L,1);
        REP(0,L.size())L[i]=output[i];
        cont_sort(L,0);
        REP(0,L.size())L[i]=output[i];
        for (i=0;i<n;i ++) current[L[i].p]=i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i - 1].nr[1] ?
        current[L[i - 1].p] : i;
        prev=current;
    }
    vl sa=current;
    lo k=0;
    vl lcp(n,0);
    vl ranks(n,0);
    REP(0,n)ranks[sa[i]]=i;b
    swap(ranks,sa);
    for(lo i=0; i<n; i++){
        if(ranks[i]==n-1){
            k=0;
            continue;
        }
        lo j=sa[ranks[i]+1];
        while(i+k<n && j+k<n && A[i+k]==A[j+k])k++;
        lcp[ranks[i]]=k;
        if(k>0)k--;
    }
    return mp(sa,lcp);
}
*/


int main(){
           lo x;
        string s;
        cin>>s;
        REP(1,s.length()){
                if(s[i]=='C'){
                        if(s[i-1]=='A'){
                                cout<<"Yes"<<endl;
                                return 0;
                        }
                }
        }
        cout<<"No";
        return 0;
}
