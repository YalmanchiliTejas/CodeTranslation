N=int(input())
A=list(map(int,input().split()))

ans=0
inf=10**9+7
flag=True
total=0
for i in range(N):
    total+=A[i]
    total%=inf

for i in range(N): 
    total-=A[i]
    ans+=A[i]*total
    ans%=inf    
          
print(ans)