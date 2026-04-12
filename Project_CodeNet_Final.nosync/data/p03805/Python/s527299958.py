import itertools as it

n, m = list(map(int,input().split()))
nodes = [[] for _ in range(n)] 
for i in range(m):
    ai, bi = list(map(int, input().split()))
    nodes[ai-1].append(bi-1)
    nodes[bi-1].append(ai-1)
cnt = 0
for perm in it.permutations(range(1,n),n-1):
    i = 0
    ok = True
    for j in perm:
        if j not in nodes[i]:
            ok = False
            break
        i = j
    if ok:
        cnt += 1
            
print(cnt)