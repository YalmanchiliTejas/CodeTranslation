N,X = map(int, input().split())

bn = [1]
pn = [1]
for i in range(N):
  bn.append(2*bn[i]+3)
  pn.append(2*pn[i]+1)

def p_eat(N,X):
  if X == 0:
    return 0
  elif X == bn[N]:
    return pn[N]
  elif bn[N-1]+1 < X:
    return pn[N-1]+1+p_eat(N-1, X-bn[N-1]-2)
  else:
    return p_eat(N-1, X-1)

print(p_eat(N,X))