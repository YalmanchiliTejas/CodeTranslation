import copy
N,M = map(int,input().split())
ls = [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    ls[a].append(b)
    ls[b].append(a)
cnt = 0
q = []
q.append([1,1,[False for i in list(range(N+1))]])
while len(q) > 0:
    [x,n,path] = q.pop()
    path[x] = True
    # print(x,n,path)
    if path.count(True) == N:
        cnt += 1
        continue
    for j in ls[x]:
        if path[j] == False:
            q.append([j,n+1,path.copy()])
print(cnt)