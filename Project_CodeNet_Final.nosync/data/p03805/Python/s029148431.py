from itertools import permutations

N,M = map(int,input().split())
masu = [[0]*N for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    masu[a][b] = 1
    masu[b][a] = 1
ans = 0
for i in permutations(range(N)):
    if i[0] != 0:continue
    for j in range(N):
        if j==N-1:
            ans += 1
            break
        if not masu[i[j]][i[j+1]]:
            break
print(ans)