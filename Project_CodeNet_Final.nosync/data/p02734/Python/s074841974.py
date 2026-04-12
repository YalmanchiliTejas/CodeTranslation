N, S = map(int, input().split())
A_array = list(map(int, input().split()))

mod = 998244353

sum_array = [0] * S
ans = 0

for i, A in enumerate(A_array):
    if A > S:
        continue
    if A == S:
        ans = (ans + (i+1) * (N-i)) % mod
        continue
    ans = (ans + sum_array[S-A] * (N-i)) % mod
    for j in range(S-1, A, -1):
        sum_array[j] = (sum_array[j] + sum_array[j-A]) % mod
    sum_array[A] = (sum_array[A] + (i+1)) % mod
    # print(sum_array, ans)
print(ans)
