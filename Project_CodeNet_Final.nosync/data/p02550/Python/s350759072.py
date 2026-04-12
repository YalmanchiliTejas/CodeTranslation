N, X, M = map(int, input().split())

exist = [0 for _ in range(M)]


def f(a, m):
  return a % m

S = 0
A = X
ls = []
for n in range(1, N + 1):
  if exist[A] == 0:
    exist[A] = n
    ls.append(A)
  else:
    term = n - exist[A]
    loop = ls[-term:]
    res = N - n + 1
    S += (res // term) * sum(loop) + sum(loop[:res % term])
    break
  S += A
  A = f(A**2, M)

print(S)