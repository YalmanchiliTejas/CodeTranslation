N=int(input())
List=list(map(int,input().split()))
count=1

for i in range(1,N):
    W=0
    for j in range(i):
        if List[j]>List[i]:
            W+=1
    if W==0:  
        count+=1
print(count)
   
    