import math
N, X, M = map(int, input().split(" "))

h = [0 for i in range(M + 1)]
r = [0 for i in range(M + 1)]

A = X
result = A
h[A] = 1
i = 2
f = True
while i < N + 1:
    r[A] = result

    A = (A * A) % M
    if A == 0:
        break
    result = result + A
    if f and h[A] > 0:
        f = False
        d = i - h[A]
        result = (result - r[A]) * int((N - i) / d) + result
        i = N - (N - i) % d
    h[A] = i
    i = i + 1
print(result)
