import itertools

n, m = map(int, input().split())
ab = [list(map(lambda x:int(x)-1, input().split())) for _ in range(m)]

nodes = [i for i in range(n)]
ls = list(itertools.permutations(nodes))

ans = 0
for root in ls:
    if root[0] != 0:
        continue
    ok = 1
    for i in range(n-1):
        if list(root[i:i+2]) not in ab and list(reversed(list(root[i:i+2]))) not in ab:
            ok = 0
    if ok:
        ans += 1

print(ans)