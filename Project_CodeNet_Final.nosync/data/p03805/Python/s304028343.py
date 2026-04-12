n,m = map(int, input().split())
link = [[] for i in range(n)]
for _ in range(m):
    a,b = map(int, input().split())
    link[a-1].append(b-1)
    link[b-1].append(a-1)

used = [0 for i in range(n)]
ans = 0
#print(link)
def dfs(now, prev):
    global ans

    if sum(used) == n:
        #print('+1')
        ans += 1

    for i in link[now]:
        #print(now,i,used)
        if i != now and used[i] == 0:
            used[i] = 1
            #print('a')
            dfs(i, now)
            #print('b')
            used[i] = 0
            #print('c')

used[0] = 1
dfs(0,-1)
print(ans)

