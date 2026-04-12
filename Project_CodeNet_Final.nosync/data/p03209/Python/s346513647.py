N, X = map(int, input().split())
a,p = [1],[1]

for i in range(N):
  a.append(2 * a[i] + 3)
  p.append(2 * p[i] + 1)
  
def runrun(N,X):
  if N == 0:
    return 0 if X <= 0 else 1
  elif X<= 1 + a[N-1]:
    return runrun(N-1, X-1)
  else:
    return p[N-1] + 1 + runrun(N-1, X-a[N-1]-2)
    
    
print(runrun(N,X))
          