from itertools import accumulate
N = int(input())
A = list(map(int, input().split()))
B = A[::-1]

B = list(accumulate(B))

mod = 10 ** 9 + 7
ans = 0
for i in range(len(A) - 1):
    ans += (B[len(A) - i - 2] * A[i]) % mod
    ans %= mod

print(ans)