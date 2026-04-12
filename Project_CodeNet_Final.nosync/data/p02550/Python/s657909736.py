N,X,M = map(int,input().split())
L = [X]
S = set([X])
idx = N
MOD = 10**9+7
for i in range(1,N):
  X = (X**2%M)
  if len(S) != len(L):
    idx = L.index(X)
    break
  L.append(X)
  S.add(X)

if idx == N:
  print(sum(L[:idx]))
else:
  k = (N-idx)%len(L[idx:])
  print(sum(L[:idx])+((N-idx)//len(L[idx:]))*sum(L[idx:])+sum(L[idx:idx+k]))