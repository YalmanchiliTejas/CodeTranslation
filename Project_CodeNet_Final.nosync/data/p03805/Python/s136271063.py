n, m = [int(i) for i in input().split()]

g = [[0 for i in range(n)] for i in range(n)]
for i in range(m):
    a, b = [int(_) for _ in input().split()]
    g[a-1][b-1] = 1
    g[b-1][a-1] = 1

s = [0]
p = 0
cnt = 0
h = -1
while True:
    if 1 in g[p][h+1:]:
        q = g[p].index(1, h+1)
        if q not in s:
            p = q
            h = -1
            s.append(p)
        else:
            h = q
    else:
        if len(s) == n:
            cnt += 1
        elif len(s) == 1:
            break
        h = p
        s.pop()
        p = s[-1]

print(cnt)