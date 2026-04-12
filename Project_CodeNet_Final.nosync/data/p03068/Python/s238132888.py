N = int(input())
S = input()
K = int(input())

a = ""
for s in S:
  if s != S[K-1]:
    a += "*"
  else:
    a += s
print(a)