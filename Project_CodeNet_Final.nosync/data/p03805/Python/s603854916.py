import itertools
N,M = map(int,input().split())
sides = []
for m in range(M):
    x,y = map(int,input().split())
    sides.append((x,y))
vertex = (i for i in range(2,N+1))
ans = 0
for v in itertools.permutations(vertex, N-1):
    T = 1
    if (1,v[0]) not in sides:
        T = 0
    for i in range(N-2):
        if (v[i],v[i+1]) not in sides and (v[i+1],v[i]) not in sides:
            T = 0
            break
    if T == 1:
        ans += 1
print(ans)

