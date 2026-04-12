import itertools

n,m=map(int,input().split())
L=[list(map(int,input().split())) for i in range(m)]
LL=[]
cnt=0
for i in range(len(L)):
    LL.append([L[i][1],L[i][0]])
Node=L+LL
Ans=[int(i)+1 for i in range(n)]
for v in itertools.permutations(Ans):
    v=list(v)
    if v[0]!=1:
        break
    tmp=0
    for i in range(n-1):
        if [v[i],v[i+1]] in Node:
            tmp+=1
    if tmp==n-1:
        cnt+=1
print(cnt)