n = int(input())
A = [*map(int, input().split())]
MOD = (10**9)+7
sum_a = sum(A)
ans = 0
for a in A[:n-1]:
    sum_a -= a
    ans += a * sum_a
    ans %= MOD
print(ans)
