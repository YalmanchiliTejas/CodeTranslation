def dfs(p, ans):
    c[p] = False
    terminal = True
    for x in e[p]:
        if c[x]:
            terminal = False
            ans = dfs(x, ans)
    
    if terminal:
        if not any(c):
            ans += 1
    c[p] = True
    
    return ans

(n,m), *s = [list(map(int, s.split())) for s in open(0)]

e = [[] for _ in range(n)]
for i,j in s:
    e[i-1].append(j-1)
    e[j-1].append(i-1)

c = [True]*n

ans = dfs(0, 0)

print(ans)