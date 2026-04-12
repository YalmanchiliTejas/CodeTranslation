#解答参照した
n,x=map(int,input().split(" "))

P=[1]
M=[1]

for i in range(1,n):
  P.append(2*P[i-1]+1)
  M.append(2*M[i-1]+3)
  
def F(n,x):
  if n==0:
    return 0 if x<=0 else 1
  elif x<=1:
    return 0
  elif 1<x<=M[n-1]+1:
    return F(n-1,x-1)
  elif x==M[n-1]+2:
    return P[n-1]+1
  elif M[n-1]+2<x<2*M[n-1]+3:
    return P[n-1]+1+F(n-1,x-2-M[n-1])
  elif x==2*M[n-1]+3:
    return 2*P[n-1]+1
  else:
    return P[n-1]+1+F(n-1,x-2-M[n-1])
    #print("OH!"+str(n))
    
print (F(n,x))