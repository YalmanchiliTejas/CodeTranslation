N,M=map(int,input().split())

ans=[]

def dfs(num,count,visit):
    #print(num,visit)
    if count==N:
        if len(visit)==N:
            ans.append(num)
        
    else:
        for index,item in enumerate(l[num]):
            if item==1 and visit.count(index)==0:
                dfs(index,count+1,visit+[index])
    return 0

            
        

l=[[0]*N for i in range(N)]

for _ in range(M):
    a,b=map(int,input().split())
    l[a-1][b-1]=1
    l[b-1][a-1]=1

dfs(0,1,[0])

print(len(ans))
#print(ans)

