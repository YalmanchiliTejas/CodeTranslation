n = int(input())
A = list(map(int,input().split()))
mod = 10**9+7

B = []
tmp = 0
for i in range(n):
    tmp += A[n-i-1]
    tmp %= mod
    B.append(tmp)

sum = 0
for i in range(n-1):
    sum += A[i]*B[n-i-2]
    sum %= mod
print(sum)