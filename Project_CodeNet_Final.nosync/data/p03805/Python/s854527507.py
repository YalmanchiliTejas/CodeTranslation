from collections import deque
n , m = map(int, input().split())
r = [[0]*(9) for i in range(9)]
ans = 0
c = 0
for i in range(m):
    a , b = map(int, input().split())
    r[a][b]=1
    r[b][a]=1
d = deque([[1,[0,1,0,0,0,0,0,0,0]]])
while d:
    p=d.popleft()
    for i in range(1,n+1):
        if r[p[0]][i]==1 and p[1][i]==0:
            t=p[1].copy()
            t[i]=1
            if sum(t)==n:
                c+=1
            d.append([i,t])
            p[1][i]=0
print(c)
