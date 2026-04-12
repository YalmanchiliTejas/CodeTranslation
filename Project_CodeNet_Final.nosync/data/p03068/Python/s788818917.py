N = int(input())
S = input()
K = int(input())
A = S[K-1]
for i in range(N):
  if S[i]!= A:
    S = S.replace(S[i], "*")
  else:
    pass
print(S)