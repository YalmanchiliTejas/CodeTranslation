A,B,C,X,Y=map(int,input().split(' '))

price=0
if X>Y:    
  N_same=Y
  flag='A'
else:
  N_same=X
  flag='B'
  
if A+B >2*C:
  price+=2*C*N_same
else:
  price+=(A+B)*N_same

if flag=='A':
  if A*(X-Y)>2*C*(X-Y):
    price+=2*C*(X-Y)
  else:
    price+=A*(X-Y)
else:
  if B*(Y-X)>2*C*(Y-X):
    price+=2*C*(Y-X)
  else:
    price+=B*(Y-X)

print(price)
