import itertools

n, m = map(int, input().split())

path = [[False]*n for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    path[a][b] = True
    path[b][a] = True

ans = 0

for i in itertools.permutations(range(n), n):
    if i[0]==0:
        for j in range(n-1):
            if not path[i[j]][i[j+1]]:
                break
        else:
            ans += 1

print(ans)