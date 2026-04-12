N = list(map(int,input()))
K = int(input())

def f(n,k):
  if len(n) == 1:
    if k == 1:
      return n[0]
    else:
      return 0
  else:
    r = n[-1]
    m = n[:-1]
    m2 = m.copy()
    m2[-1] = m2[-1] - 1
    for i in range(len(m)):
      if m2[-i] < 0:
        m2[-i] += 10
        m2[-i-1] = m2[-i-1] - 1
    if k == 1:
      m = n[:-1]
      return f(m,1) + 9
    else:
      return f(m,k) + f(m,k-1) * r + f(m2,k-1) * (9-r)
    
print(f(N,K))