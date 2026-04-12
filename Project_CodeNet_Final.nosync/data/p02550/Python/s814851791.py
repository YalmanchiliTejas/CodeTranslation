N, X, M = map(int, input().split())
D = {i:0 for i in range(M)}
L = [X]
c = X
D[X]=0
S = X
for i in range(1, N):
  c = (c**2)%M
  if D[c]==0:
    D[c] = i
    L.append(c)
    S += c
    continue
  else:
    p, q = D[c], i
    break
else:
  print(S)
  exit()  
cycle = L[p:q]
cycle_sum = sum(cycle)
cycle_num = (N-q)//(q-p)
rest = (N-q)%(q-p)
S += cycle_sum*cycle_num
S += sum(cycle[:rest])
print(S)