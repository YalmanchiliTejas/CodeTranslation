N=int(input())
A=list(map(int,input().split()))
ans=1
H=A[0]
for i in range(1,N):
    if H<=A[i]:
        ans+=1
        H=A[i]
print(ans)
