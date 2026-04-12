n=int(input())
A=list(map(int,input().split()))
m=A[0]
ans=int(1)
for i in range(1,n):
    if m<=A[i]:
        ans+=1
        m=A[i]
print(ans)