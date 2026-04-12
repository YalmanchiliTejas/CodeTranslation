from itertools import permutations
import copy
n,m = map(int,input().split())
g = [[0]*n for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    g[a-1][b-1] = 1
    g[b-1][a-1] = 1
stock = list(permutations([i for i in range(1,n)]))
#print(stock)
ans = 0
for i in stock:
    h = copy.deepcopy(g)
    cnt = 1
    p = 0
    for k in i:
        if h[p][k] == 0:
            break
        else:
            cnt += 1
            p = k
    if cnt == n:
        ans += 1
    #print(i,cnt,h,g)
print(ans)