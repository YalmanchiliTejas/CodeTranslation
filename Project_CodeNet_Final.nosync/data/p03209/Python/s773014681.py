N, X = map(int,input().split())
thk = [1]
p = [1]

for i in range(N-1):
  thk.append(2*thk[-1]+3)
  p.append(2*p[-1]+1)

def burger(N,X):
  if N==0:
    if X<=0:
      return 0
    else:
      return 1
  elif X <= thk[N-1]+1:
    return (burger(N-1,X-1))
  
  else:
    return p[N-1] + 1 + burger(N-1,X-thk[N-1]-2)
  
print(burger(N,X))