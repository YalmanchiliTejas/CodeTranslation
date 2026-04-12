a, b = map(int, input().split())
distances = [list(map(int, input().split())) for _ in range(a)]
n = 202
m = 0
g = [[] for _ in range(n)]
for i in range(100):
    g[i].append((i + 1, 'X'))
    m += 1
for i in range(100):
    g[i + 101].append((i + 102, 'Y'))
    m += 1
for p in range(0, 101):
    for q in range(0, 101):
        r = -10000000
        for i in range(a):
            for j in range(b):
                r = max(r, distances[i][j] - p * (i + 1) - q * (j + 1))
        if r >= 0:
            g[p].append((n - q - 1, r))
            m += 1
for i in range(a):
    for j in range(b):
        d = [float('inf')] * n
        d[0] = 0
        s = [0]
        while s:
            p = s.pop()
            for to, dist in g[p]:
                if dist == 'X':
                    dist = i + 1
                elif dist == 'Y':
                    dist = j + 1
                s.append(to)
                d[to] = min(d[to], d[p] + dist)
        if d[-1] != distances[i][j]:
            print('Impossible')
            exit(0)
print('Possible')
print(n, m)
for i in range(n):
    for node, dist in g[i]:
        print(i + 1, node + 1, dist)
print(1, n)
