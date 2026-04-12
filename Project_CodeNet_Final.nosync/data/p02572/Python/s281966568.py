N = int(input())
A_ = list(map(int, input().split()))
A = []
mod = 10 ** 9 + 7
for i, a_ in enumerate(A_[::-1]):
    if i == 0:
        A.append(a_ % mod)
    else:
        a = (a_ + A[-1]) % mod
        A.append(a)
A = A[::-1]
A = A[1:]
ans = 0
for i, a in enumerate(A_[:-1]):
    ans += A[i] * a % mod
    ans %= mod

print(ans)