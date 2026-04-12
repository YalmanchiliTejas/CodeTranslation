import itertools

n, m = map(int, input().split())
h = [[0]*n for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    h[a-1][b-1] = 1
    h[b-1][a-1] = 1

ans = 0
x = list(itertools.permutations(range(1, n+1)))
for i in range(len(x)):
    flag = False
    if x[i][0] == 1:
        flag = True
        for j in range(n-1):
            if h[x[i][j]-1][x[i][j+1]-1] == 0:
                flag = False
                break
    if flag:
        ans += 1
print(ans)