from copy import deepcopy

def wfs(tree, root, node_num):
    lost_list = [root]

    def _wfs(tree, root, lost_list) -> int:
        if len(lost_list) == node_num:
            return 1
        counter = 0
        for i in tree[root]:
            if i not in lost_list:
                tmp = deepcopy(lost_list)
                tmp.append(i)
                counter += _wfs(tree, i, tmp)
        return counter

    return _wfs(tree, 0, lost_list)


n, m = input().rstrip().split()
n, m = int(n), int(m)
v = [list() for i in range(n)]
for _ in range(m):
    line = [int(i) - 1 for i in input().rstrip().split()]
    v[line[0]].append(line[1])
    v[line[1]].append(line[0])

print(wfs(v, 0, n))