N=int(input())
A=list(map(int,input().split()))

# 累積和
s=[0]
K=0
for i in range(N):
    K+=A[i]
    s.append(K)
U=0
for i in range(N-1):
    U+=A[i]*(s[N]-s[i+1])
print(U%(10**9+7))