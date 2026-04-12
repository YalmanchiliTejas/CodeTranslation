#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Segment {
  int l, r;  // [l, r] (inclusive)
  int64 v;
};

// T: The type of values.
// U: The type of operators.
// Three conditions.
// - apply_op(merge(x1, x2), o) = merge(apply_op(x1, o), apply_op(x2, o))
// - apply_op(apply_op(x, o1), o2) = apply_op(x, merge_op(o1, o2))
// - apply_op(x, empty_op) = x
// Verified: AOJ-DSL2F, AOJ-DSL2G, AOJ-DSL2H, AOJ-DSL2I
template<typename T, typename U>
class LazyPropagationSegmentTree {
 private:
  function<T(T, T)> merge;
  T empty_value;
  function<U(U, U)> op_merge;
  U empty_op;
  function<T(T, U)> apply_op;
  int num_nodes;  
  vector<T> nodes;
  vector<U> op_nodes;

  void DoLazyPropagation(int node_index) {
   if (op_nodes[node_index] != empty_op) {
      nodes[node_index] = apply_op(nodes[node_index], op_nodes[node_index]);
      if (node_index < num_nodes / 2) {
        op_nodes[2 * node_index] =
            op_merge(op_nodes[2 * node_index], op_nodes[node_index]);
        op_nodes[2 * node_index + 1] =
            op_merge(op_nodes[2 * node_index + 1], op_nodes[node_index]);
      }
      op_nodes[node_index] = empty_op;
    }
  }

  void ApplyOpRangeInternal(
      int node_index, int node_l, int node_r, int l, int r, U op) {
    DoLazyPropagation(node_index);

    if (node_r <= l || r <= node_l) return;

    if (l <= node_l && node_r <= r) {
      op_nodes[node_index] = op;
      DoLazyPropagation(node_index);
      return;
    }
    int node_m = (node_l + node_r) / 2;
    ApplyOpRangeInternal(2 * node_index, node_l, node_m, l, r, op);
    ApplyOpRangeInternal(2 * node_index + 1, node_m, node_r, l, r, op);
    nodes[node_index] = merge(nodes[2 * node_index], nodes[2 * node_index + 1]);
  }

  T GetRangeInternal(
      int node_index, int node_l, int node_r, int l, int r) {
    DoLazyPropagation(node_index);

    if (node_r <= l || r <= node_l) return empty_value;

    if (l <= node_l && node_r <= r) {
      return nodes[node_index];
    }

    int node_m = (node_l + node_r) / 2;
    return merge(
        GetRangeInternal(2 * node_index, node_l, node_m, l, r),
        GetRangeInternal(2 * node_index + 1, node_m, node_r, l, r));
  }

 public:
  LazyPropagationSegmentTree(
      function<T(T, T)> in_merge, T in_empty_value,
      function<U(U, U)> in_op_merge, U in_empty_op,
      function<T(T, U)> in_apply_op, vector<T> values) :
          merge(in_merge), empty_value(in_empty_value), op_merge(in_op_merge),
          empty_op(in_empty_op), apply_op(in_apply_op) {
    int n = values.size();
    num_nodes = 1;
    while (num_nodes < n) num_nodes *= 2;
    num_nodes *= 2;
    nodes = vector<T>(num_nodes, empty_value);
    op_nodes = vector<U>(num_nodes, empty_op);
    for (int i = 0; i < values.size(); ++i) {
      nodes[num_nodes / 2 + i] = values[i];
    }
    for (int i = num_nodes / 2 - 1; i >= 1; i--) {
      nodes[i] = merge(nodes[2 * i], nodes[2 * i + 1]);
    }
  }

  // Applies the operator to the range [l, r).
  void ApplyOpRange(int l, int r, U op) {
    return ApplyOpRangeInternal(1, 0, num_nodes / 2, l, r, op);
  }

  T GetRange(int l, int r) {
    return GetRangeInternal(1, 0, num_nodes / 2, l, r);
  }
  
  T Get(int i) { return GetRange(i, i + 1); }
};

constexpr int DEBUG = 1;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<Segment>> r_to_segments(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    int64 v;
    cin >> l >> r >> v;
    l--;
    r--;
    Segment segment({l, r, v});
    r_to_segments[r].push_back(segment);
  }

  function<int64(int64, int64)> merge_fn = [](int64 x, int64 y) {
    return max(x, y);
  };
  int64 empty_value = INT64_MIN;
  function<int64(int64, int64)> op_merge_fn = [](int64 x, int64 y) {
    return x + y;
  };
  int64 empty_op = 0;
  function<int64(int64, int64)> apply_op_fn =
      [](int64 value, int64 op) -> int64 {
    if (value == INT64_MIN) return INT64_MIN;
    return value + op;
  };
  vector<int64> values(n);

  auto segment_tree = LazyPropagationSegmentTree<int64, int64>(
      merge_fn, empty_value, op_merge_fn, empty_op, apply_op_fn, values);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      int64 range_max = max(0LL, segment_tree.GetRange(0, i));
      // if (DEBUG) cout << "i: " << i << " range_max: " << range_max << endl;
      segment_tree.ApplyOpRange(i, i + 1, range_max);
    }
    for (Segment segment : r_to_segments[i]) {
      segment_tree.ApplyOpRange(segment.l, segment.r + 1, segment.v);
    }
  }
  int64 ans = max(0LL, segment_tree.GetRange(0, n));
  cout << ans << endl;
}
