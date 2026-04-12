N = int(input())
A = input().split()

toA = 0
for i in range(N):
    A[i] = int(A[i])
    toA += A[i]

ans = 0
for i in range(0, N):
    toA -= A[i]
    ans += A[i]*toA

print(ans % 1000000007)