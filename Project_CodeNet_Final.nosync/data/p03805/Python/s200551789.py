from itertools import permutations

n, m = map(int, input().split())
links = [[0]*n for i in range(n)]
for i in range(m):
        a, b = map(int, input().split())
        links[a-1][b-1] = links[b-1][a-1] = 1

ans = 0
for path in permutations(range(n)):
        if path[0]: continue
        can = 1
        for i in range(n-1):
                if links[path[i]][path[i+1]]==0: can = 0
        ans += can
print(ans)