N, X, M = map(int, input().split())

appearance = [0] * (M + 1)
cum_sum = [0]
A = X
appearance[A] = 1
cum_sum.append(A)
a = 1
for a in range(2, N + 1):
    A = (A**2)%M
    if appearance[A] != 0:
        n = a - 1
        break
    appearance[A] = a
    cum_sum.append(cum_sum[a - 1] + A)
else: n = a

k = appearance[A]
l = (N - n) // (n - k + 1)
m = (N - n) - (n - k + 1)*l + k - 1

ans = cum_sum[n] + (cum_sum[n] - cum_sum[k - 1])*l + cum_sum[m] - cum_sum[k - 1]
print(ans)