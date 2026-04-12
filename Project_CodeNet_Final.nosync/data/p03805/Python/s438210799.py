import bisect
n,m = map(int,input().split())

g = [[ ] for i in range(n+1)]

for i in range(m):
    a,b = map(int,input().split())
    g[a].append(b)
    g[b].append(a)

    #print(bisect.bisect_left(g[a],b))
    #g[a][] = b
    #g[a].append(b)
    #g[b].append(a)

#g[4].sort()
    
ans = 0

def dfs(x,check):
    #print(check,x)
    ans = 0
    if not False in check:
        #print(ans)
        return 1
        #check[x] = 0
        #print(x)
    #print(check)
    for i in g[x]:
        if check[i] == True:
            continue
        #print(i,check)
        check[i] = True
        ans += dfs(i,check)
        check[i] = False
    
    return ans
    
check = [False] * (n+1)
check[0] = True
check[1] = True

print(dfs(1,check))

