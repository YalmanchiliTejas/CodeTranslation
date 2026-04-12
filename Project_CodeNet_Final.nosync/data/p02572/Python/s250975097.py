N = int(input())
A = list(map(int, input().split()))

diff = A[0]
res = 0

for i in range(1, N):
    res += diff*A[i]
    diff += A[i]
    res %= 10**9+7
    diff %= 10**9+7
print(res)