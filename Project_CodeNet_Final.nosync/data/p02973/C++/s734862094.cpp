#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <stack>
 
template<class T>
class UnionFindTree{
public:
    UnionFindTree(const T N){
        tree = std::vector<T>(N);
        for(T i=0; i<N; ++i){
            tree[i] = i;
        }
        nGroup = N;
    }

    T root(const T idx){
        T tmp = idx;
        std::stack<T> stack;
        while(tree[tmp] != tmp){
            stack.push(tmp);
            tmp = tree[tmp];
        }
        while(!stack.empty()){
            tree[stack.top()] = tmp;
            stack.pop();
        }
        return tmp;
    }

    void merge(const T idx1, const T idx2){
        if(!same(idx1, idx2)){
            tree[root(idx1)] = root(idx2);
            --nGroup;
        }
    }

    bool same(const T idx1, const T idx2){
        return root(idx1) == root(idx2);
    }

    T groups(){
        return nGroup;
    }

private:
    std::vector<T> tree;
    T nGroup;
};



int main(int argc, char *argv[]){
  int N;
  std::cin >> N;
  std::vector<long int>A(N);
  for(auto &a : A){
    std::cin >> a;
  }
  std::vector<int>AIdx(N);
  std::iota(AIdx.begin(),AIdx.end(),0);
  std::sort(AIdx.begin(),AIdx.end(),
    [&A](const auto &lhs, const auto &rhs){
      return A[lhs] > A[rhs] || (A[lhs] == A[rhs] && lhs < rhs);
    });

  std::set<int> set;

  UnionFindTree<int> tree(N);
  for(const auto &idx : AIdx){
    auto pIter = set.upper_bound(idx);
    if(pIter != set.end()){
      tree.merge(*pIter, idx);
      set.erase(*pIter);
    }
    set.emplace(idx);
  }
  std::cout << tree.groups() << std::endl;
}