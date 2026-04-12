def rs(X, Y, i):
  if i not in Y:
    return 0
  elif len(Y)==1:
    return 1
  Y.remove(i)
  
  total=0
  X_tmp=[x for x in X if i in x]
  for x in X_tmp:
    st=set(x)&set(Y)
    if st!=set():
      target=list(st)[0]
    else:
      continue
    total+=rs(X, Y[:], target)
    
  return total
  

N,M=map(int, input().split())
X=[list(map(int,input().split())) for _ in range(M)]
Y=[i+1 for i in range(N)]
print(rs(X, Y, 1))