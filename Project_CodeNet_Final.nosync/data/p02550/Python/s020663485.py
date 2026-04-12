N, X, M = map(int, input().split())
A = [X]
S = [0, X]
Y = [-1] * M
f = 0
s = X
for i in range(1, M * 5 + 10):
    a = A[-1] ** 2 % M
    s += a
    A.append(a)
    S.append(s)
    if f == 0 and Y[a] >= 0:
        rp = i - Y[a]
        t = Y[a]
        f = 1
    Y[a] = i
if N < M * 5 * 0:
    print(S[N])
else:
    j = N % rp + (t // rp + 1) * rp
    print(S[j] + (S[t + rp] - S[t]) * (N - j) // rp)