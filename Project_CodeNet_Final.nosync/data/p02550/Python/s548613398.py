N,X,M=map(int,input().split())
a = X
hist = [a]
indices = [-1]*M
indices[a] = 0
flag=0
for i in range(1,min(10**6,N)):
  a = a**2 % M
  if indices[a] != -1:
    idx = indices[a]
    flag=1
    break
  hist.append(a)
  indices[a] = i
  
if flag==0:
  print(sum(hist))
  exit()
  
cycle = hist[idx:]
margin = hist[:idx]
q,r = divmod((N-len(margin)),len(cycle))
print(sum(margin)+sum(cycle)*q+sum(cycle[:r]))