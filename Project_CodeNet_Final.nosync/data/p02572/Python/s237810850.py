N=int(input())
A=list(map(int, input().split()))
B=[A[0]]
for i in range(1,N):
    B.append(B[i-1]+A[i])
p=10**9+7
ans=0
for i in range(1,N):
    ans+=A[i]*B[i-1]
ans%=p
print(ans)
