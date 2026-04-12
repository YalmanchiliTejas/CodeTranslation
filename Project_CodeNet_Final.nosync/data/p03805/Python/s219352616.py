import itertools

n, m = map(int, input().split())
path = [[False] * n for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    path[a-1][b-1] = True
    path[b-1][a-1] = True

#print(path)
ans = 0
x = list(itertools.permutations(range(1,n)))
for i in range(len(x)):
    u = list(x[i])
    w = [0] + u
    ok = 0
    for j in range(n-1):
        if path[w[j]][w[j+1]]:
            ok += 1
        else:
            break

    if ok == n-1:
        #print(w)
        ans += 1

print(ans)