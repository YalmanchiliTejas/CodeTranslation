q=[]
qq=[]
def dfs(j,q,count,n,qq):
    if len(qq)==n:
        count+=1
        return count    
    for j2 in q[j]:
        if not j2 in qq:
            qq.append(j2)
            count=dfs(j2,q,count,n,qq)
            qq.pop()
    return count

n,m=map(int,input().split())
q=[[]*2 for i in range(n)]
for i in range(m):
    ai,bi=list(map(int,input().split()))
    if not q[bi-1] in q[ai-1]:
        q[ai-1].append(bi-1)    
    if not q[ai-1] in q[bi-1]:
        q[bi-1].append(ai-1)    

count=0
j=0
qq=[j]
count=dfs(j,q,count,n,qq)
print(count)
