n = int(input())
A = list(map(int, input().split()))

# sum_A[j] := A[0]～A[j-1]までの和
sum_A = [0 for _ in range(n)]
for j in range(1, n):
    sum_A[j] = sum_A[j - 1] + A[j - 1]

ans = 0
for j in range(1, n):
    ans += A[j] * sum_A[j]
    ans = ans % (10**9 + 7)
print(ans)