n, m = map(int, input().split())
ab=[list(map(int, input().split())) for i in range(m)]
e=[[0]*10 for i in range(10)]
for abi in ab:
    e[abi[0]][abi[1]]=1
    e[abi[1]][abi[0]]=1
ans=0
def dfs(l, v):
    l.append(v)
    if len(l)==n:
        global ans
        ans+=1
        return
    for i in range(10):
        if e[v][i]==1 and i not in l:
            ll=[i for i in l]
            dfs(ll, i)
    return
dfs([],1)
print(ans)
