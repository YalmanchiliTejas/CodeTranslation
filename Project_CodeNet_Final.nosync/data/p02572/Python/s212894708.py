N=int(input())
A=list(map(int,input().split()))
total=0
ans=0
d=[0]*210000

for i in range(N):
    total+=A[i]
    d[i]=total

for j in range(N):
    ans+=A[j]*(total-d[j])

print(ans%1000000007)