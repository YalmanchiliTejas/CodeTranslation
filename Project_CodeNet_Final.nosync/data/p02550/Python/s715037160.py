N,X,mod = map(int,input().split())
visited = [False for i in range(mod)]
visited[X]=True
mod_loop = [X]
now = X
while visited[now**2%mod] == False:
    mod_loop.append(now**2%mod)
    visited[now**2%mod] = True
    now = now**2%mod
now=now**2%mod

que = []
for i in range(len(mod_loop)):
    if mod_loop[i] == now:
        que.append(i)

leftsum = mod_loop[:que[0]]

looper = mod_loop[que[0]:]

if N<=len(leftsum):
    print(sum(leftsum[:N]))
else:
    ans = sum(leftsum)
    u,v = divmod(N-len(leftsum),len(looper))
    ans += u*sum(looper) + sum(looper[:v])
    print(ans)