from itertools import permutations
n,m = map(int, input().split())
d = {}
for _ in range(m):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    if a not in d:
        d[a] = {}
    if b not in d:
        d[b] = {}
    d[a][b] = d[b][a] = 1

ans = 0
for route in permutations(range(1,n)):
    if route[0] not in d[0]:
        continue
    for j in range(n-2):
        if route[j+1] not in d[route[j]]:
            break
    else:
        ans += 1

print(ans)
