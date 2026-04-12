N = int(input())
A = list(map(int, input().split()))

ans = 0
sum_list = sum(A)
for i in range(N):
    ans += A[i] * (sum_list - A[i])
    ans %= 1000000007
    sum_list -= A[i]
print(ans)
