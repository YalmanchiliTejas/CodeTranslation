N, X = map(int, input().split())
NLs = [1]
NPs = [1]
for L in range(1, N+1):
  NLs.append(NLs[L-1]*2+3)
  NPs.append(NPs[L-1]*2+1)
#print(NLs, NPs)
def sub(L, X):
  if L == 0:
    return X
  if X <= 1:
    return 0
  elif X <= 1+NLs[L-1]:
    return sub(L-1, X-1)
  elif X == 1+NLs[L-1]+1:
    return NPs[L-1]+1
  elif X <= 1+NLs[L-1]+1+NLs[L-1]:
    return NPs[L-1]+1+sub(L-1, X-1-NLs[L-1]-1)
  else:
    return NPs[L-1]*2+1
r = sub(N, X)
print(r)
