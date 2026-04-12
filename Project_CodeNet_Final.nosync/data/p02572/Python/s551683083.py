N = int(input())
A = list(map(int,input().split()))
a = 10**9 + 7
sum = A[0]
ans = 0
for i in range(1,N):
    ans = (ans+sum*A[i])%a
    sum += A[i]
print(ans)