def dfs(num,s):
    cnt = 0
    s.add(num)
    if(len(s)==N):
        s.discard(num)
        return 1
    for x in li[num]:
        if(x not in s):
            cnt += dfs(x,s)
    s.discard(num)
    return cnt
#%%
N,M = [int(x) for x in input().split()]
li = [[]for _ in range(N+1)]
for _ in range(M):
    a,b = [int(x) for x in input().split()]
    li[a].append(b)
    li[b].append(a)
#%%
sets = set()
ans = dfs(1,sets)
print(ans)
