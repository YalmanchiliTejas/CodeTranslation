n = int(input())
A = [*map(int, input().split())]
MOD = (10**9)+7
ans = 0

# print(A)

sum_a = [0] * (n+1)
for i in range(n):
    sum_a[i+1] = sum_a[i] + A[i]

# print(sum_a)

for i in range(n):
    ai = A[i]
    ans = (ans + ai*(sum_a[-1] - sum_a[i+1])) % MOD
    # print(sum_a[-1], sum_a[i+1],sum_a[-1] - sum_a[i+1] )

# for i in range(n):
#     for j in range(i+1, n):
#         ans = (ans + A[i]*A[j]%MOD) % MOD
ans = (ans + MOD) % MOD
print(ans)
