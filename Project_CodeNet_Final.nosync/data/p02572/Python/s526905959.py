n=int(input())
aa=list(map(int,input().split()))
total=0
c=sum(aa)

for i in range(n):
    c-=aa[i]
    total+=aa[i]*c
   
x=10**9+7
ans=total%x
print(ans)