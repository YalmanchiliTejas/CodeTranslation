N,M=map(int,input().split())
a=[0 for k in range(M)]
b=[0 for k in range(M)]
for k in range(M):
    a[k],b[k]=map(int, input().split())
def dfs(route,new):
    route=route+new
    if len(route)==N+1:
        return 1
    count=0
    for k in range(M):
        if a[k]==route[-1] and b[k] not in route:
            count+= dfs(route,[b[k]])
    for k in range(M):
        if b[k]==route[-1] and a[k] not in route:
            count+= dfs(route,[a[k]])
    return count

print(dfs([0],[1]))
            

