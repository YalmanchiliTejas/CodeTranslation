N = int(input())
A = list(map(int, input().split()))

ans = 0
sum = sum(A)

for i in range(1,N):
    sum -= A[i-1]
    ans += A[i-1] * sum
    ans = ans % 1000000007

print(ans)
