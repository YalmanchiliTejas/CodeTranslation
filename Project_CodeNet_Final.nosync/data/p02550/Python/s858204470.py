N, X, M = map(int, input().split())
A = [X]
A_dict = {X}
a = X
s = X
r = 0
r0 = 0
l = 0
amari = 0

for i in range(M+1):
  a = a ** 2 % M
  if a in A_dict:
    r0 = A.index(a)
    l = len(A[r0:])
    r = (N - i - 1) // l
    amari = (N - i - 1) % l
    s = s + sum(A[r0:])*r + sum(A[r0:r0+amari])
    break
  A.append(a)
  A_dict.add(a)
  s += A[-1]

print(s)