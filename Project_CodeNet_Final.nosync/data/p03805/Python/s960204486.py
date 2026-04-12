import itertools

n,m=map(int,input().split())
uselist=[]
for _ in range(m):
    ad=list(map(int,input().split()))
    uselist.append(ad)
cnt=0
for i in itertools.permutations(range(1,n+1)):
    if i[0]==1:
        flag=True
        for j in range(n-1):
            if [i[j],i[j+1]]  not in uselist and [i[j+1], i[j]] not in uselist:
                flag =False
                break
            else:
                continue
        if flag==True:
            cnt+=1
        else:
            continue
        
print(cnt)            
