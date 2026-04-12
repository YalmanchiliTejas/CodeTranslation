N = int(input())
A = [int(i) for i in input().split()]
B = [0]*N
res = 0
B[N-1] = A[N-1]
for i in range(1, N):
    B[N-i-1] = B[N-i] + A[N-i-1]
for i in range(N-1):
    res = (res + A[i] * B[i+1]) % (10**9+7)
print(res)