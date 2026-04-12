import itertools

n, m = map(int, input().split())
p = [[0]*n for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    p[a-1][b-1] = 1
    p[b-1][a-1] = 1

c = list(itertools.permutations(range(n)))
cnt = 0
for i in range(len(c)):
    if c[i][0] == 0:
        for j in range(n-1):
            if p[c[i][j]][c[i][j+1]] != 1:
                break
        else:
            cnt += 1
print(cnt)