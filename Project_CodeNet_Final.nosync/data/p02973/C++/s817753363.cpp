#include<iostream>
#include<memory>
#include<random>

using Size = int;

template<typename Key, typename Value> class RandomizedBinarySearchTree {
 public:
  // 追加
  void insert(const Key& key, const Value& value) {
    auto i = index(root_, key);
    auto s = split(root_, i);
    auto n = std::make_unique<Node>(key, value);
    root_ = merge(s.first, n);
    root_ = merge(root_, s.second);
  }
  // 削除
  void erase(const Key& key) {
    auto i = index(root_, key);
    auto s1 = split(root_, i);
    auto s2 = split(s1.second, 1);
    root_ = merge(s1.first, s2.second);
  }
  // 検索
  std::pair<Key, Value> find(const Size& i) const {return find(root_, i);}
  // 二分探索
  Size lower_bound(const Key& key) {return index(root_, key);}
  // 要素数
  Size size() const {return size(root_);}
  // デバッグ用
  void debug() {
    traverse(root_,0);std::cout<<std::endl<<std::endl;
  }
  void traverse(const auto& node, auto d)const{
    if(!node) return;
    traverse(node->r_child,d+1);
    for(auto i=0;i<d;++i)std::cout<<"    ";
    std::cout<<"_"<<node->key;
//     std::cout<<"_"<<node->value;
//     std::cout<<"_"<<size(node);
    std::cout<<std::endl;
    traverse(node->l_child,d+1);
  }

 private:
  // 頂点
  struct Node {
    Key key;
    Value value;
    Size size;
    std::unique_ptr<Node> l_child, r_child;
    Node(const Key& k, const Value& v) : key(k), value(v), size(1) {}
  };
  // 頂点のポインタ
  using Ptr = std::unique_ptr<Node>;

  // 部分木に含まれる頂点数
  Size size(const Ptr& node) const {return node ? node->size : 0;}
  // 頂点の情報を子の情報をもとに更新
  Ptr update(Ptr& node) {
    if(!node) return std::move(node);
    node->size = size(node->l_child) + size(node->r_child) + 1;
    return std::move(node);
  }
  // key から index を検索
  Size index(const Ptr& node, const Key& key) const {
    if(!node) return 0;
    if(key == node->key) return size(node->l_child);
    if(key < node->key)  return index(node->l_child, key);
    else                 return size(node->l_child) + 1 + index(node->r_child, key);
  }
  // index から key, value を検索
  std::pair<Key, Value> find(const Ptr& node, const Size& i) const {
    if(size(node->l_child) == i) return std::make_pair(node->key, node->value);
    if(i < size(node->l_child))  return find(node->l_child, i);
    else                         return find(node->r_child, i - size(node->l_child) - 1);
  }
  // 木の結合
  Ptr merge(Ptr& lhs, Ptr& rhs) {
    if(!lhs) return std::move(rhs);
    if(!rhs) return std::move(lhs);
    auto to_left = std::rand() % (size(lhs) + size(rhs)) < size(lhs);
    if(to_left) {
      lhs->r_child = merge(lhs->r_child, rhs);
      return update(lhs);
    } else {
      rhs->l_child = merge(lhs, rhs->l_child);
      return update(rhs);
    }
  }
  // key が小さな頂点 i 個からなる木と, それ以外からなる木とに分割
  std::pair<Ptr, Ptr> split(Ptr& node, const Size& i) {
    if(!node) return std::make_pair(nullptr, nullptr);
    if(i <= size(node->l_child)) {
      auto s = split(node->l_child, i);
      node->l_child = std::move(s.second);
      return std::make_pair(std::move(s.first), update(node));
    } else {
      auto s = split(node->r_child, i - size(node->l_child) - 1);
      node->r_child = std::move(s.first);
      return std::make_pair(update(node), std::move(s.second));
    }
  }

  // 変数
  Ptr root_;
};

#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for(auto& i: A) cin >> i;

  auto hash = [&](auto i) {return 1000000 * A[i] - i;};

  RandomizedBinarySearchTree<long long, int> T;
  T.insert(-1000000, -1);
  for(auto i = 0; i< N; ++i) {
    auto x = T.lower_bound(hash(i)) - 1;
    if(x != 0) T.erase(T.find(x).first);
    T.insert(hash(i), -1);
  }
  cout << T.size() - 1 << endl;
}
