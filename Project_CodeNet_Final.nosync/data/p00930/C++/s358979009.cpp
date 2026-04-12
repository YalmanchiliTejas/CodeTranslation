#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)


template <typename T> class SegTree{
  struct node_t{
    T   min;
    T   sum;
    T   add;
    int left_pos;
    int right_pos;
  };
    
  int                 N;
  std::vector<T>      A;
  std::vector<node_t> data;

  inline void eval(int k, int l, int r){
    if(data[k].add == 0) return;
    
    if(r - l > 1){
      data[2 * k + 1].add += data[k].add;
      data[2 * k + 2].add += data[k].add;
    }
    
    data[k].sum += data[k].add * (r - l);
    data[k].min += data[k].add;
    data[k].add  = 0;
  }
  
  inline void merge(int k){
    int chl  = k * 2 + 1;
    int chr  = k * 2 + 2;
    T   lmin = data[chl].min;
    T   rmin = data[chr].min;
    data[k].sum = data[chl].sum + data[chr].sum;
    data[k].min = std::min(lmin, rmin);
    data[k].left_pos = lmin <= rmin ? data[chl].left_pos : data[chr].left_pos;
    data[k].right_pos = lmin >= rmin ? data[chr].right_pos : data[chl].right_pos;
  }
    
  void build(int k, int l, int r){
    if(r - l == 1){
      data[k].min = A[l];
      data[k].sum = A[l];
      data[k].left_pos = data[k].right_pos = l;
      data[k].add = 0;
    }else{
      int m   = (l + r) / 2;
      int chl = 2 * k + 1;
      int chr = 2 * k + 2;
      build(chl, l, m);
      build(chr, m, r);
      merge(k);
    }
  }
  
  void add(int a, int b, T x, int k, int l, int r){
    eval(k, l, r);
    if(b <= l || r <= a){
      return;
    }else if(a <= l && r <= b){
      data[k].add += x;
      eval(k, l, r);
    }else{
      int m   = (l + r) / 2;
      int chl = k * 2 + 1;
      int chr = k * 2 + 2;
      add(a, b, x, chl, l, m);
      add(a, b, x, chr, m, r);
      merge(k);
    }
  }
  
  T min(int a, int b, int &pos, int k, int l, int r, bool left_min_pos){
    eval(k, l, r);
    if(b <= l || r <= a){
      return std::numeric_limits<T>::max();
    }else if(a <= l && r <= b){
      pos =left_min_pos ? data[k].left_pos :  data[k].right_pos;
      return data[k].min;
    }else{
      int m   = (l + r) / 2;
      int chl = k * 2 + 1;
      int chr = k * 2 + 2;
      int lpos = -1, rpos = -1;
      T lmin = min(a, b, lpos, chl, l, m, left_min_pos);
      T rmin = min(a, b, rpos, chr, m, r, left_min_pos);
      merge(k);
      pos = lmin < rmin ? lpos : rpos;
      if (lmin == rmin){
        pos  = (left_min_pos ? lpos : rpos);
      }
      return std::min(lmin, rmin);
    }
  }
  
  T sum(int a, int b, int k, int l, int r){
    eval(k, l, r);
    if(b <= l || r <= a){
      return 0;
    }else if(a <= l && r <= b){
      return data[k].sum;
    }else{
      int m   = (l + r) / 2;
      int chl = k * 2 + 1;
      int chr = k * 2 + 2;
      T   vl  = sum(a, b, chl, l, m);
      T   vr  = sum(a, b, chr, m, r);
      merge(k);
      return vl + vr;
    }
  }
  
public:
  SegTree(size_t N) : N(N), A(std::vector<T>(N, 0)){
    data.resize(4 * N);
    build(0, 0, N);
  }
    
  SegTree(const std::vector<T> &A) : N(A.size()), A(A){
    data.resize(4 * N);
    build(0, 0, N);
  }
    
  void add(int l, int r, T x) {add(l, r, x, 0, 0, N);}
  T min(int l, int r, int &pos, bool left_min_pos = true)
  {pos = -1; return min(l, r, pos, 0, 0, N, left_min_pos);}
  T min(int l, int r){int tmp;return min(l, r, tmp);}
  T sum(int l, int r){return sum(l, r, 0, 0, N);}
};


bool check(string& S){
  int p=0;
  for(auto ch : S){
    if(ch == '(') ++p;
    else --p;
    if( p < 0) return false;
  }
  return p == 0;
}

int main(int argc, char *argv[])
{
  int N, Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  
  vector<int> open_sum(N + 1, 0);
  vector<int> open_pos(N);
  
  REP(i, N){
    open_sum[i + 1] = open_sum[i] + (S[i] == '(' ? 1 : -1);
    open_pos[i] = (S[i] != '(');
  }
  
  assert(open_sum[N] == 0);
  SegTree<int> sum_seg(open_sum);
  SegTree<int> pos_seg(open_pos);
  
  set<int> close_parens;
  set<int> open_parens;
  REP(i, N) if(S[i] == ')') close_parens.insert(i);
  REP(i, N) if(S[i] == '(') open_parens.insert(i);

  string naive_S = S;
  
  while (Q--){
    int q;
    cin >> q; q--;

    // cout << "before " << endl;
    // cout << naive_S << endl;
    
    if(naive_S[q] == '(') naive_S[q] = ')';
    else naive_S[q] = '(';

    // for(int i = 0; i < N; ++i){
    //   char ch = naive_S[i];
    //   if(naive_S[i] == '(') naive_S[i] = ')';
    //   else naive_S[i] = '(';
    //   if(check(naive_S)) break;
    //   naive_S[i] = ch;
    // }

    
    
    // for(int i = 0; i < N; ++i)
    //   cout << sum_seg.sum(i,i+1) << " ";
    // cout << endl;
    
    if (S[q] == '('){
      close_parens.insert(q);
      open_parens.erase(q);
      int min_idx = *close_parens.begin();
      close_parens.erase(min_idx);
      open_parens.insert(min_idx);
      
      if (min_idx != q){
        S[min_idx] = '(';
        S[q] = ')';
        
        sum_seg.add(q + 1, N + 1, -2);
        sum_seg.add(min_idx + 1, N + 1, 2);
        
        // pos_seg.add(min_idx, min_idx + 1, -1);
        // pos_seg.add(q, q + 1, 1);
      }
      cout << min_idx + 1 << endl;
    } else if (S[q] == ')'){
      if (sum_seg.sum(q + 1, q + 2) == 0) {
        cout << q + 1 << endl;
      } else {
        sum_seg.add(q + 1, N + 1, 2);
        
        int sum_pos = -1, pos_pos = -1;
        int min_val = sum_seg.min(0, q + 1, sum_pos, false);
        {
          int low = 0;
          int up = q+1;
          while(low+1 < up){
            int mid = (low+up)/2;
            if(sum_seg.min(mid,q+1) >= 2)
              up = mid;
            else
              low = mid;
          }
          sum_pos = up-2;
        }
        int pos_val;// = pos_seg.min(sum_pos + 1, q + 1, pos_pos, true);
        //cout << sum_pos << endl;
        pos_pos = *open_parens.lower_bound(sum_pos+1);
        
        assert(S[pos_pos] == '(');
        cout << pos_pos + 1 << endl;
        

        sum_seg.add(pos_pos + 1, N + 1, -2);
        
        // pos_seg.add(q, q + 1, -1);
        // pos_seg.add(pos_pos, pos_pos + 1, 1);

        if (q != pos_pos){
          
          close_parens.erase(q);
          close_parens.insert(pos_pos);
        
          open_parens.insert(q);
          open_parens.erase(pos_pos);

          S[q] = '(';
          S[pos_pos] = ')';
        }
      }
    } else { assert(false);}
    // cout << naive_S << endl;
    // cout << S << endl;
    // assert(naive_S == S);
    
  } 
 
  return 0;
}
    