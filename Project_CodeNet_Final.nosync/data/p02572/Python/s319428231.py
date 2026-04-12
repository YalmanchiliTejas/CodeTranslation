N = int(input())
A = list(map(int, input().split()))
ans = 0
sum_A = [0]*N
for j in range(N-1, 0, -1):
    sum_A[j] = A[j]+sum_A[(j+1) % N]
for i in range(N-1):
    ans += A[i]*sum_A[i+1]
    ans %= 10**9+7
print(ans)