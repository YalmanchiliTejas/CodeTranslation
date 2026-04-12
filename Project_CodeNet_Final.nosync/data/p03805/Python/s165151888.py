import itertools
N,M = map(int,input().split())
ab = [list(map(int,input().split())) for _ in [0]*M]
connect = [[] for _ in [0]*N]
for a,b in ab:
    connect[a-1].append(b-1)
    connect[b-1].append(a-1)
ans = 0
for a in itertools.permutations(range(1,N)):
    a = (0,) + a
    for i in range(N-1):
        if not a[i+1] in connect[a[i]]:
            break
    else:
        ans+=1
print(ans)