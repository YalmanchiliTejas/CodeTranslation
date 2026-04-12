N = int(input())
S = str(input())
K = int(input())
s = list(S)
k = S[K-1]
for i in range(N):
  n = S[i]
  if  n != k:
    S = S.replace(n, "*")
print(S)
