import  itertools 
n,m=map(int,input().split())
edges=[[0]*n  for i in range(n)]
#print(edges)
for _ in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    edges[a][b]=1
    edges[b][a]=1
#print(edges)
#generate all permutations
l=[i for i in range(n)]
p_obj=itertools.permutations(l)
ans=0
for i in p_obj:
    #print(i)
    if i[0]>0:
        break
    flag=True
    for j in range(1,n):
        if edges[i[j-1]][i[j]]==0:
            flag=False
            break
    if flag:
        ans+=1
print(ans)

