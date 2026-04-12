import itertools
N, M = map(int, input().split())
ab = []
for i in range(M):
    ab.append(list(map(int, input().split())))
ans = 0
if M >= N - 1:
    for i in list(itertools.combinations(ab, N - 1)):
        g = {}
        for j in range(N):
            g[j + 1] = []
        for j, k in i:
            g[j].append(k)
            g[k].append(j)
        if len(g[1]) == 1:
            p = 1
            q = g[p][0]
            for j in range(N - 2):
                l = g[q]
                if len(l) != 2:
                    break
                l.remove(p)
                p = q
                q = l[0]
            else:
                ans += 1
print(ans)