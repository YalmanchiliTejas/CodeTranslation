class UnionFindNode:
    def __init__(self, group_id, parent=None, value=None):
        self.group_id_ = group_id
        self.parent_ = parent
        self.value = value
        self.rank_ = 1
        self.member_num_ = 1

    def is_root(self):
        return not self.parent_

    def root(self):
        parent = self
        while not parent.is_root():
            parent = parent.parent_
            self.parent_ = parent
        return parent

    def find(self):
        root = self.root()
        return root.group_id_

    def rank(self):
        root = self.root()
        return root.rank_

    def unite(self, unite_node):
        root = self.root()
        unite_root = unite_node.root()

        if root.group_id_ != unite_root.group_id_:
            if root.rank() > unite_root.rank():
                n_root, child = root, unite_root
            else:
                n_root, child = unite_root, root
            child.parent_ = n_root
            n_root.rank_ = max(n_root.rank_, child.rank_ + 1)
            n_root.member_num_ = n_root.member_num_ + child.member_num_

N, = map(int, input().split())
X,Y = [],[]
for i in range(1, N+1):
    x, y = map(int, input().split())
    X.append((x,i))
    Y.append((y,i))
X = sorted(X, key=lambda x:x[0])
Y = sorted(Y, key=lambda x:x[0])
Es = set()
for i in range(N-1):
    Es.add((tuple(sorted([X[i][1], X[i+1][1]])), abs(X[i][0]-X[i+1][0])))
    Es.add((tuple(sorted([Y[i][1], Y[i+1][1]])), abs(Y[i][0]-Y[i+1][0])))
node_list = [UnionFindNode(i) for i in range(N+1)]
Es = sorted(Es, key=lambda x:x[1])
r = 0
for (x, y), c in Es:
    if node_list[x].find() == node_list[y].find():
        continue
    r += c
    node_list[x].unite(node_list[y])
print(r)
