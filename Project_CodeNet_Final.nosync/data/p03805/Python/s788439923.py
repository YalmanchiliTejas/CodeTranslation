# 全探索で間に合う
from collections import deque

N,M=map(int,input().split())
friend=[[] for _ in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    friend[a-1].append(b-1)
    friend[b-1].append(a-1)

count=0
stack=deque([str(0)])
while stack:
    tmp=stack.pop()
    if len(tmp)==N:
        count+=1
    else:
        label=[-1]*N
        for i in range(len(tmp)):
            label[int(tmp[i])]=1
        for i in friend[int(tmp[-1])]:
            if label[i]==-1:
                stack.append(tmp+str(i))
print(count)