N = int(input().strip())

A = []
for _ in range(N):
  A.append(int(input().strip()))
  
A = list(sorted(A))

if N % 2 == 1:
  coef = [-2] * ((N - 2) // 2) + [-1, -1] + [2] * ((N - 2) // 2 + 1)
  s1 = sum(c * a for c, a in zip(coef, A))
  coef = [-2] * ((N - 2) // 2 + 1) + [1, 1] + [2] * ((N - 2) // 2)
  s2 = sum(c * a for c, a in zip(coef, A))
  print(max(s1, s2))
else:
  coef = [-2] * ((N - 2) // 2) + [-1, 1] + [2] * ((N - 2) // 2)
  print(sum(c * a for c, a in zip(coef, A)))
