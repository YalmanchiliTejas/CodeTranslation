N = int(input())
S = input()
K = int(input())

for s in S:
  if S[K-1] != s:
    S  = S.replace(s,"*")

print(S)