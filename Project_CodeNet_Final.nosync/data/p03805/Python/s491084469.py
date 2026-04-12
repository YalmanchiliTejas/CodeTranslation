from itertools import permutations
n,m = map(int,input().split())
path = [[False] * n for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    path[a-1][b-1] = True
    path[b-1][a-1] = True
ans = 0
for ss in permutations(range(n)):
    s = list(ss)
    key = 1
    if s[0] != 0:
        key = 0
    for i in range(n-1):
        if path[s[i]][s[i+1]] == False:
            key = 0
    if key:
        ans += 1
print(ans)