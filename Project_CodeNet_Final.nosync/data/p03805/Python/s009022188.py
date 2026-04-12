
import sys
import itertools
n,m = map(lambda x: int(x),input().split())
tree = [[]*n for i in range(n)]
l = [int(i) for i in range(n)]
ans_count = 0
for _ in range(m) :
    a,b = map(lambda x: int(x),input().split())
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)
for v in itertools.permutations(l) :
    if v[0] != 0 :
        continue
    flag = 1
    for w in range(n-1) :
        if not v[w] in tree[v[w+1]] :
            flag = 0
    if flag == 1 :
        ans_count += 1
print(ans_count)
