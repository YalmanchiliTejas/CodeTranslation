h, w = map(int, input().split())
A = [None] * h
for i in range(h):
  A[i] = input()

while ('.' * w in A):
  A.remove('.' * w)

B = [''.join(col) for col in zip(*A)]

while ('.' * len(A) in B):
  B.remove('.' * len(A))


A = [''.join(col) for col in zip(*B)]

for a in A:
  print(''.join(a))
