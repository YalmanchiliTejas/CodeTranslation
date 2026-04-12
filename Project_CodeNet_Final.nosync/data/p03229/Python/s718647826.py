N = int(input())
signs = [1, -1]
coefs = [[-1],[1]]
i = 0
while i < N-2:
  j = 0
  while j < 2:
    coefs[j].append(2*signs[j])
    signs[j] *= -1
    j += 1
  i += 1
coefs[0].append(signs[0])
coefs[1].append(signs[1])
coefs[0].sort()
coefs[1].sort()
A = sorted([int(input()) for _ in range(N)])
print(max([sum([A[i]*coef[i]  for i in range(N)]) for coef in coefs]))