from itertools import accumulate

N, X, M = map(int, input().split())
s = []
A = X
ind = {}
i = 0
while A not in ind:
    s.append(A)
    ind[A] = i
    A = A * A % M
    i += 1
L = i - ind[A]
s = [0] + list(accumulate(s))
ans = s[ind[A]] + (s[-1] - s[ind[A]]) * ((N - ind[A]) // L) + s[ind[A] + (N - ind[A]) % L] - s[ind[A]]
print(ans)