q=[]
qq=[]
def dfs(j,q,icnt,count,n,qq):
    if len(qq)==n:
        count+=1
#        print("1",n,j,icnt,count,q[j],qq)
        return count
    icnt+=1
    
    for j2 in q[j]:
        if not j2 in qq:
            qq.append(j2)
#            print("2",n,j,icnt,count,q[j],qq)
            count=dfs(j2,q,icnt,count,n,qq)
            qq.pop()
#        print("3",n,j,icnt,count,q[j],qq)
    return count

n,m=map(int,input().split())
ab=[[0]*2 for i in range(m)]
for i in range(m):
    ab[i]=list(map(int,input().split()))

#n=3
#m=3
#ab=[[1,2],[1,3],[2,3]]

#n=7
#m=7
#ab=[[1,3],[2,7],[3,4],[4,5],[4,6],[5,6],[6,7]]

q=[[]*2 for i in range(n)]
for i in range(m):
    if not q[ab[i][1]-1] in q[ab[i][0]-1]:
        q[ab[i][0]-1].append(ab[i][1]-1)    
    if not q[ab[i][0]-1] in q[ab[i][1]-1]:
        q[ab[i][1]-1].append(ab[i][0]-1)    
#print(q)    

count=0
j=0
qq=[j]
icnt=1
count=dfs(j,q,icnt,count,n,qq)
print(count)