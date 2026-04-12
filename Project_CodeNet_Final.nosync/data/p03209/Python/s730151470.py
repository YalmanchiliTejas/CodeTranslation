N,K = map(int,input().split())
import sys
sys.setrecursionlimit(10000000)

a, p = [1], [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)
def dfs(N,X):
    #print(N,X)
    if N == 0:
        return 0 if X != 1 else 1
    elif X <= 1 + a[N-1]:
        return dfs(N-1, X-1)
    elif X == 2 + a[N-1]:
        return p[N-1] + 1
    elif X <= 2 + 2*a[N-1]:
        return p[N-1] + 1 + dfs(N-1, X-2-a[N-1])
    else:
        return 2*p[N-1]+1
    
print(dfs(N,K))