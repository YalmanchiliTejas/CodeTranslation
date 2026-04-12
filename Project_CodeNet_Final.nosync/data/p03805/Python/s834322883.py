n,m = map(int,input().split())
e = [[False]*n for _ in range(n)]
visited = [False]*n
for _ in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    e[a][b] = True
    e[b][a] = True

def traverse(t,d):
    #print(t,d)
    visited[t] = True

    ans = 0
    is_end = True

    for i in range(n):
        if e[t][i] and not visited[i]:
            is_end = False
            ans += traverse(i, d+1)


    visited[t] = False
    if is_end:
        if d != n-1:
            return 0
        else:
            return 1
    
    return ans

print(traverse(0, 0))
