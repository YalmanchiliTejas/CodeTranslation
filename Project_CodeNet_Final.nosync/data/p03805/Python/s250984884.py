def DFS(n):
    global ans
    stack.append(n)
    for i in range(M):
        if graf[i][0] ==n:
            if graf[i][1] not in stack:DFS(graf[i][1])
        if graf[i][1]==n:
            if graf[i][0] not in stack:DFS(graf[i][0])
    if len(stack)==N:ans+=1
    stack.pop()

N,M=map(int,input().split())
graf,stack,ans=[],[],0
for _ in range(M):
    graf.append(list(map(int,input().split())))
DFS(1)
print(ans)