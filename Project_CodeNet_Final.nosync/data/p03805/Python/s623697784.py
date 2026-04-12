# coding: utf-8
count=0
def check(now,v,n):
    global count
    v[now]=1
    if sum(v)==n:
        count+=1
    else:
        for i in range(8):
            if v[i]==0 and g[now][i]==1:
                check(i,v[:],n)

n,m=map(int,input().split())
g=[[0 for i in range(8)]for i in range(8)]
for i in range(m):
    a,b=map(int,input().split())
    g[a-1][b-1]=1
    g[b-1][a-1]=1
check(0,[0,0,0,0,0,0,0,0][:],n)
print(count)