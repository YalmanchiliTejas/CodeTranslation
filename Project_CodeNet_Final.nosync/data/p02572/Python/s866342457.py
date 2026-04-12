mod=10**9+7
n=int(input())
A=list(map(int,input().split()))

ans=0
num=sum(A[1:])
for i in range(n-1):
    ans +=num*A[i]
    num -=A[i+1]
print(ans%mod)