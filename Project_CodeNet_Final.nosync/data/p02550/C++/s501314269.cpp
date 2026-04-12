#include <bits/stdc++.h>
using namespace std;

#define F first
#define FF first.first
#define FS first.second
#define S second
#define SF second.first
#define SS second.second
#define ii pair<int,int>
#define iii pair<ii, int>
#define iiii pair<ii, ii>
#define viiii vector< iiii >
#define viii vector< iii >
#define vii vector< ii >
#define vi vector< int >
#define vvi vector<vector< int > >
#define int int64_t


#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sortv(V) sort(all(V))
#define reversev(V) reverse(all(V))
#define uniquev(V) sortv(V),(V).erase(unique(all(V)),(V).end())

#define gcd(a, b) (__gcd((a), (b)))
#define lcm(a, b) (((a)/__gcd(a, b)) * b)

#define yes cout << "Yes" << endl
#define no cout << "No" << endl

// Trace dinâmico (parameter pack (c++11))
template<typename T>
void println(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void println(T a, Args... args) { cout << a << " "; println(args...); }

template<typename T>
void print(T a) { cout << a; }
template<typename T, typename... Args>
void print(T a, Args... args) { cout << a << " "; print(args...); }

template<typename T>
void printv(T a, string last="\n") {
    for(auto el: a)
      print(el, "");
    print(last);
}


template<typename T>
void scan(T& a) { cin >> a ; }
template<typename T, typename... Args>
void scan(T& a, Args&&... args) { cin >> a; scan(args...); }

//Functions

bool contain(int value, vector<int> &v){
   int l = 0, r = v.size();
   while(l<r){
      int m = (l+r)/2;
      if( v[m]<value ){
         l = m+1;
      }else{
         r = m;
      }
   }
   return l!=v.size() and v[l]==value;
}

int firstGreater(int value, vector<int> &v){
   int l = 0, r = v.size();
   while(l<r){
      int m = (l+r)/2;
      if( v[m]>value ){
         r = m;
      }else{
         l = m+1;
      }
   }

   return l;
}

int firstGreaterOrIgual(int value, vector<int> &v){
   int l = 0, r = v.size();
   while(l<r){
      int m = (l+r)/2;
      if( v[m]>=value ){
         r = m;
      }else{
         l = m+1;
      }
   }
   return l;
}


#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000000000000LL
#define MOD 1000000007LL
#define endl '\n'
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

//Classes
struct BitTrieNode{   BitTrieNode *child[2];   int len;   BitTrieNode(){      child[0] = child[1] = NULL;      len = 0;   }};struct BitTrie {   BitTrieNode *root;   BitTrie(){      root = new BitTrieNode();   }   void addNumber(int number){      BitTrieNode *cur = root;      cur->len++;      for(int b = 30; b >= 0; b--){         if( cur->child[ !!(number&(1<<b)) ] == NULL ){            cur->child[ !!(number&(1<<b)) ] = new BitTrieNode();         }         cur=cur->child[ !!(number&(1<<b)) ];      }   }   int maxXor(int number){      BitTrieNode *cur = root;      int ans = 0;      for(int b = 30; b >= 0; b--){         if(cur==NULL){            break;         }         if( cur->child[ !(number&(1<<b)) ] != NULL ){            ans += (1<<b);            cur = cur->child[ !(number&(1<<b)) ];         }else{            cur = cur->child[ !!(number&(1<<b)) ];         }      }      return ans;   }};
struct KThOneTree {   int len;   vector<int> left;   vector<int> right;   vector<int> ones;   vector<int> lazy;   int(*func)(int,int);   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   int elements(int id){ return right[id]-left[id]+1; }   void init(){      left = vector<int>(4*len);      right = vector<int>(4*len);      ones = vector<int>(4*len);      lazy = vector<int>(4*len);   }   KThOneTree(int _len,           int(*_func)(int,int)=[](int x,int y){return x+y; } ){      len = _len;      func = _func;      init();      build(0, 0, len-1);   }   template<class RandomIterator>   KThOneTree(RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x,int y){return x+y; } ){      len = distance(begin, end);      func = _func;      init();      build(0, 0, len-1, begin);   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }   }   template<class RandomIterator>   void build(int id, int l, int r, RandomIterator begin ){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m, begin);         build( rightChild(id), m+1,  r, begin);         ones[id] = ones[ leftChild(id) ] + ones[rightChild(id)];      }else{         ones[id] = begin[l];      }   }   void push(int id){      if( lazy[id]==0 ) return;      if( lazy[id]%2 ) ones[id] = (elements(id)-ones[id]);      if(left[id]!=right[id]){         lazy[ leftChild(id) ] = (lazy[id]+lazy[ leftChild(id) ]);         lazy[ rightChild(id) ] = (lazy[id]+lazy[ rightChild(id) ]);      }      lazy[id] = 0;   }   int query(int ql, int id = 0){      push(id);      if( elements(id)<ql or ones[id]<ql )return -1;      if(left[id]==right[id]){         return 0;      }else{         push( leftChild(id) );         push( rightChild(id) );         if( ones[leftChild(id)]>=ql ) return query(ql, leftChild(id));         else return elements(leftChild(id)) +                     query(ql-ones[leftChild(id)], rightChild(id));      }   }   int update(int ql, int qr, int id = 0){      push(id);      if( left[id]>qr or right[id]<ql ){      }else if( ql<=left[id] and right[id]<=qr ){         lazy[id] += 1;         push(id);      }else{         ones[id] = func(                  update(ql,qr, leftChild(id)),                  update(ql,qr, rightChild(id))         );      }      return ones[id];   }};
template<class T>struct Matrix{   int rows;   int columns;   vector< vector<T> > grid;   Matrix(){         rows = columns = 0;         grid = vector< vector<T> >();   }   Matrix(int _rows, int _columns){      rows = _rows;      columns = _columns;      grid = vector< vector<T> >(rows, vector<T>(columns));   }   bool inside(int row, int column){      return row>=0 and row<rows and column>=0 and column<columns;   }   vector<T>& operator [] (int row){      return grid[row];   }   void fill(T value){      for(int i = 0; i < rows; i++)         for(int j = 0; j < columns; j++)            grid[i][j] = value;   }   void clock_rotate(){      vector< vector<T> > result = vector< vector<T> >(columns, vector<T>(rows));      for(int i = 0; i < columns; i++){         for(int j = 0; j < rows; j++){            result[i][j] = grid[rows-j-1][i];         }      }      swap(columns, rows);      grid = result;   }   void print(){      for(int i = 0; i < rows; i++){         for(int j = 0; j < columns; j++){            cout << grid[i][j] << ' ';         }         printf("\n");      }   }};
struct MaxCountTree {   int len;   int INF;   vector<int> max_value;   vector<int> occ;   vector<int> left;   vector<int> right;   int(*func)(int,int);   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   void init(){      max_value = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      occ = vector<int>(4*len);      setINF();   }   MaxCountTree( int _len, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = _len;      func = _func;      init();      build(0, 0, len-1);   }   template<class RandomIterator>   MaxCountTree( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = distance(begin, end);      func = _func;      init();      build(0, 0, len-1, begin);   }   void setINF(){      INF = 1;      while( INF < (INF<<2) ) INF = (INF<<2);      INF = func(INF, -INF );   }   template<class RandomIterator>   int build(int id, int l, int r, RandomIterator begin){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         max_value[id] = func(                        build( leftChild(id), l,  m, begin),                        build( rightChild(id), m+1,  r, begin)                     );         occ[id] = (max_value[id]==max_value[leftChild(id)]?occ[leftChild(id)]:0) +                  (max_value[id]==max_value[rightChild(id)]?occ[rightChild(id)]:0);         return max_value[id];      }else{         occ[id] = 1;         return max_value[id] = begin[l];      }   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }      max_value[id] = 0;      occ[id] = l-r+1;   }   pair<int,int> query(int ql, int qr, int id = 0){      if( left[id]>qr or right[id]<ql ) return {-INF, 0};      else if( ql<=left[id] and right[id]<=qr ) return {max_value[id], occ[id]};      else {         pair<int,int> q1 = query(ql,qr,leftChild(id));         pair<int,int> q2 = query(ql,qr,rightChild(id));         int value=func(q1.first,q2.first);         int cc = (value==q1.first?q1.second:0) +                  (value==q2.first?q2.second:0);         return {value, cc};      }   }   int update(int value, int loc, int id = 0){      if( left[id]>loc or right[id]<loc ){         return max_value[id];      }else if( loc==left[id] and loc==right[id] ){         return max_value[id] = value;      }else{         max_value[id] = func(                  update(value, loc, leftChild(id)),                  update(value, loc, rightChild(id))         );         occ[id] = (max_value[id]==max_value[leftChild(id)]?occ[leftChild(id)]:0) +                   (max_value[id]==max_value[rightChild(id)]?occ[rightChild(id)]:0);         return max_value[id];      }   }};
struct MaxSegmentTree {   int len;   int INF;   vector<int> max_segment;   vector<int> preSum;   vector<int> posSum;   vector<int> sum;   vector<int> left;   vector<int> right;   int(*func)(int,int);   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   void init(){      max_segment = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      preSum = vector<int>(4*len);      posSum = vector<int>(4*len);      sum = vector<int>(4*len);      setINF();   }   MaxSegmentTree( int _len, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = _len;      func = _func ;      init();      build(0, 0, len-1);   }   template<class RandomIterator>   MaxSegmentTree( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = distance(begin, end);      func = _func;      init();      build(0, 0, len-1, begin);   }   void setINF(){      INF = 1;      while( INF < (INF<<2) ) INF = (INF<<2);      INF = func(INF, -INF );   }   void updateNode(int id){      sum[id] = sum[leftChild(id)] + sum[rightChild(id)];      preSum[id] = func(preSum[leftChild(id)],                        sum[leftChild(id)] + preSum[rightChild(id)] );      posSum[id] = func(posSum[rightChild(id)],                        sum[rightChild(id)] + posSum[leftChild(id)] );      max_segment[id] = func(max_segment[leftChild(id)],                             max_segment[rightChild(id)]);      max_segment[id] = func(max_segment[id],                             preSum[rightChild(id)]+posSum[leftChild(id)]);   }   template<class RandomIterator>   void build(int id, int l, int r, RandomIterator begin){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m, begin);         build( rightChild(id), m+1,  r, begin);         updateNode(id);      }else{         max_segment[id] = sum[id] = posSum[id] = preSum[id] = begin[l];      }   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }   }   int query(int id = 0){      return max_segment[id];   }   void update(int value, int loc, int id = 0){      if( left[id]>loc or right[id]<loc ){         return;      }else if( loc==left[id] and loc==right[id] ){         max_segment[id] = sum[id] = posSum[id] = preSum[id] = value;      }else{         update( value, loc, leftChild(id));         update( value, loc, rightChild(id));         updateNode(id);      }   }};
struct MaxTree {   int len;   int INF;   vector<int> max_value;   vector<int> left;   vector<int> right;   int(*func)(int,int);   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   MaxTree( int _len, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = _len;      max_value = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      func = _func ;      setINF();      build(0, 0, len-1);   }   template<class RandomIterator>   MaxTree( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = distance(begin, end);      max_value = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      func = _func;      setINF();      build(0, 0, len-1, begin);   }   void setINF(){      INF = 1;      while( INF < (INF<<2) ) INF = (INF<<2);      INF = func(INF, -INF );   }   template<class RandomIterator>   int build(int id, int l, int r, RandomIterator begin){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         return max_value[id] = func(                        build( leftChild(id), l,  m, begin),                        build( rightChild(id), m+1,  r, begin)                     );      }else{         return max_value[id] = begin[l];      }   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }   }   int query(int ql, int qr, int id = 0){      if( left[id]>qr or right[id]<ql ) return -INF;      else if( ql<=left[id] and right[id]<=qr ) return max_value[id];      else return func( query(ql,qr,leftChild(id)), query(ql,qr,rightChild(id)));   }   int update(int value, int loc, int id = 0){      if( left[id]>loc or right[id]<loc ){         return max_value[id];      }else if( loc==left[id] and loc==right[id] ){         return max_value[id] = value;      }else{         return max_value[id] = func(                  update(value, loc, leftChild(id)),                  update(value, loc, rightChild(id))         );      }   }};
struct PrefixSumBit{   int len;   vector<int> bit;   /*1 to len*/   PrefixSumBit(int _len){      len = _len;      bit = vector<int>(len+1);   }   /*LeastSignificantBit*/   static int LSB(int value){      return value & -value;   }   void add(int value, int id){      while( id <= len ){         bit[id]+=value;         id += LSB(id);      }   }   int preSum(int id){      int ans = 0;      while(id){         ans += bit[id];         id -= LSB(id);      }      return ans;   }};
struct rangeSumTree {   int len;   vector<int> tree;   vector<int> left;   vector<int> right;   vector<int> lazy;   int(*func)(int,int);   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   int elements(int id){ return right[id]-left[id]+1; }   rangeSumTree(int _len,           int(*_func)(int,int)=[](int x,int y){return x+y; } ){      len = _len;      tree = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      lazy = vector<int>(4*len);      func = _func;      build(0, 0, len-1);   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }   }   void push(int id){      if( lazy[id]==0 ) return;      tree[id] += lazy[id]*elements(id);      if(left[id]!=right[id]){         lazy[ leftChild(id) ] += lazy[id];         lazy[ rightChild(id) ] += lazy[id];      }      lazy[id] = 0;   }   int query(int ql, int qr, int id = 0){      push(id);      if( left[id]>qr or right[id]<ql ) return 0;      else if( ql<=left[id] and right[id]<=qr ) return tree[id];      else return func( query(ql,qr,leftChild(id)), query(ql,qr,rightChild(id)));   }   int update(int value, int ql, int qr, int id = 0){      push(id);      if( left[id]>qr or right[id]<ql ){      }else if( ql<=left[id] and right[id]<=qr ){         lazy[id] += value;         push(id);      }else{         tree[id] = func(                  update(value, ql,qr, leftChild(id)),                  update(value, ql,qr, rightChild(id))         );      }      return tree[id];   }};
struct rangeSumUpdateRangeMaxQueryTree {   int len;   vector<int> great;   vector<int> left;   vector<int> right;   vector<int> lazy;   int leftChild(int id){ return id*2+1; }   int rightChild(int id){ return id*2+2; }   int elements(int id){ return right[id]-left[id]+1; }   rangeSumUpdateRangeMaxQueryTree(int _len){      len = _len;      great = vector<int>(4*len);      left = vector<int>(4*len);      right = vector<int>(4*len);      lazy = vector<int>(4*len);      build(0, 0, len-1);   }   void build(int id, int l, int r){      left[id]=l;      right[id]=r;      if(l!=r){         int m = (l+r)/2;         build( leftChild(id), l,  m);         build( rightChild(id), m+1,  r);      }   }   void push(int id){      if( lazy[id]==0 ) return;      great[id] += lazy[id];      if(left[id]!=right[id]){         lazy[ leftChild(id) ] += lazy[id];         lazy[ rightChild(id) ] += lazy[id];      }      lazy[id] = 0;   }   int query(int ql, int qr, int id = 0){      push(id);      if( left[id]>qr or right[id]<ql ) return -(oo);      else if( ql<=left[id] and right[id]<=qr ) return great[id];      else return max( query(ql,qr,leftChild(id)), query(ql,qr,rightChild(id)));   }   int update(int value, int ql, int qr, int id = 0){      push(id);      if( left[id]>qr or right[id]<ql ){      }else if( ql<=left[id] and right[id]<=qr ){         lazy[id] += value;         push(id);      }else{         great[id] = max(                  update(value, ql,qr, leftChild(id)),                  update(value, ql,qr, rightChild(id))         );      }      return great[id];   }};
struct SimpleGraph{   int vertices;   vector<vector<int>> edges;   vector<int> &operator [] (int i){      return edges[i];   }   SimpleGraph(){      vertices=0;   }   SimpleGraph(int _vertices){      vertices = _vertices;      edges = vector<vector<int>>(vertices);   }   void add_bi_edge(int v, int u){      edges[v].push_back(u);      edges[u].push_back(v);   }   void add_edge(int v, int u){      edges[v].push_back(u);   }   vector<int> distanceFrom(int v){      vector<int> dist(vertices, -1);      dist[v] = 0;      queue<int> bfs;      bfs.push( v );      while(bfs.size()){         int v = bfs.front();         bfs.pop();         for(int u: edges[v]){            if( dist[u]==-1 ){               dist[u] = dist[v]+1;               bfs.push( u );            }         }      }      return dist;   }   int longestVerticeFrom(int v){      vector<int> distA = distanceFrom(v);      int longest = 0;      for(int i = 0; i < vertices; i++){         if(  distA[longest] < distA[i] )            longest = i;      }      return longest;   }   int longestDistanceFrom(int v){      vector<int> distA = distanceFrom(v);      int longest = 0;      for(int i = 0; i < vertices; i++){         if(  distA[longest] < distA[i] )            longest = i;      }      return distA[longest];   }   int diameter(){      int longest = longestVerticeFrom(0);      return longestDistanceFrom(longest);   }};
struct SparseTable {   int len;   int log;   int INF;   int(*func)(int,int);   vector< vector<int> > table;   template<class RandomIterator>   SparseTable( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){      len = distance(begin, end);      func = _func;      setINF();      setLog();      table = vector< vector<int> >(log+1, vector<int>(len, -INF) );      for(int i = 0; i < len; i++){         table[0][i] = begin[i];      }      for(int i = 1; i <= log; i++){         for(int j = 0; j < len; j++){            if( j+(1<<i)-1 < len ){               table[i][j] = func(table[i-1][j], table[i-1][j+(1<<(i-1))]);            }         }      }   }   void setINF(){      INF = 1;      while( INF < (INF<<2) ) INF = (INF<<2);      INF = func(INF, -INF );   }   void setLog(){      log = 1;      while( (1<<log) < len  ) log++;   }   int query(int l, int r){      if(l==r)return table[0][l];      int n = 0;      while(l+(1<<(n+1)) < r) n++;      return func( table[n][l], table[n][r-(1<<n)+1] );   }};
struct SuffixArray{   int len;   string s;   vector<int> P;   vector<int> pos;   vector<int> lcp;   void mySort(vector< int > &p, vector<int> &level){      vector<int> ctn(len);      for( auto &it: level ){         ctn[ it ]++;      }      vector<int> start(len);      for(int i = 1; i < len; i++) start[i] = start[i-1]+ctn[i-1];      vector< int > p_new(len);      for( auto &it:p) {         p_new[ start[ level[it] ]++ ] = it;      }      p = p_new;   }   SuffixArray(const string _s){      s = _s+"$";      len = s.size();      P = vector<int>(len);      vector<int> level = vector<int>(len);      {         vector< pair<char,int> > v(len);         for(int i = 0; i < len; i++) v[i] = {s[i], i} ;         sort( v.begin(), v.end() );         for(int i = 0; i < len; i++) P[i] = v[i].second;         level[ P[0] ] = 0;         for(int i = 1; i < len; i++){            P[i] = v[i].second;            level[ P[i] ] = level[ P[i-1] ] + (v[i].first>v[i-1].first);         }      }      for(int k = 0; (1<<(k)) < len; k++){         for(int i = 0; i < len; i++)            P[i] = (P[i] - (1<<k) + len)%len;         mySort( P, level );         vector<int> level_new(len);         level_new[ P[0] ] = 0;         for(int i = 1; i < len; i++){            pair<int,int> prev = {level[P[i-1]], level[ (P[i-1] +(1<<k))%len ] };            pair<int,int> now = {level[P[i]], level[ (P[i] +(1<<k))%len ] };            level_new[ P[i] ] = level_new[ P[i-1] ] + (now>prev);         }         level = level_new;      }      pos = vector<int> (len);      for(int i = 0; i < len; i++){         pos[ P[i] ] = i;      }      lcp = vector<int> (len-1);      int k = 0;      for(int i = 0; i+1 < len; i++){         int prev = P[ pos[ i ] - 1];         while( s[i+k] == s[prev+k] ) k++;         lcp[ pos[i]-1 ] = k--;         k = max( k, int(0LL) );      }   }   /*   menor = 1   maior = 0   igual = -1   */   int compStr(int in, string &_s){      for(int i = 0; i < _s.size(); i++){         if( s[ (P[in]+i)%len ] != _s[i] ){            return s[ (P[in]+i)%len ] < _s[i];         }      }      return -1;   }   int first_match(string &_s){      if( _s.size() > len ) return -1;      int l = 0, r = len-1;      while(l < r){         int m = (l+r)/2;         if( compStr(m, _s)==1 ){            l = m+1;         }else{            r = m;         }      }      return compStr(l, _s)==-1?l:-1;   }   int last_match(string &_s){      if( _s.size() > len ) return -1;      int l = 0, r = len-1;      while(l < r){         int m = (l+r+1)/2;         if( compStr(m, _s) ){            l = m;         }else{            r = m-1;         }      }      return compStr(l, _s)==-1?l:-1;   }   int count_substr(string &_s){      int l = first_match(_s);      int r = last_match(_s);      return l>=0?r-l+1:0;   }   int is_substr(string &_s){      return first_match(_s) != -1;   }   void print(){      printf("--- My Array ---\n");      for(int i = 0; i < len; i++){         cout << P[i] << ' ' <<  (s.c_str() + P[i]) << '\n';      }   }   long long count_substrs(){      long long ans = 0;      for(int i = 1; i < len; i++){         ans += (len-P[i]-1)-lcp[i-1];      }      return ans;   }   static string lcs(const string a, const string b){      string myS = a+"@"+b;      SuffixArray myArray( myS );      int lcsLen=0;      int lcsid=0;      for(int i = 1; i < myArray.len; i++){         int c1 = myArray.P[i-1]<a.size();         int c2 = myArray.P[i]<a.size();         if( c1!=c2 and myArray.lcp[i-1]>lcsLen ){            lcsLen = myArray.lcp[i-1];            lcsid = myArray.P[i-1];         }      }      string ans = myArray.s.substr(lcsid, lcsLen);      return ans;   }};

//Main
int N, X, M, K, L, R, J, P, CASES;
int A,B,C;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> N >> X >> M;

   int ans = X;
   vector<int> mark(M);
   vector<int> seq;
   vector<int> rep;

   for(int i=1; i < N; i++){
      X = (X*X)%M;

      if(mark[X]){
         int remain = N-i;
         int len = (i-mark[X]);
         vi rep;
         int sum = 0;
         for(int j = mark[X]-1; j < i-1; j++){
            sum += seq[j];
            rep.pb(seq[j]);
         }
         sum *= (remain/len);
         remain = (remain%len);
         for(int j = mark[X]-1; remain and j < i-1; j++){
            sum += seq[j];
            remain--;
         }
         ans += sum;
         break;
      }

      seq.push_back(X);
      mark[X]=i;
      ans += X;
   }
   println(ans);
   /*
   20 3 10
   */
}





















