n, x = map(int, input().split())

BP = [1]
P = [1]

for i in range(n):
  BP.append(BP[i]*2+3)
  P.append(P[i]*2+1)
  
def check_P_num(n, x):
  
  if n==0:
    return 1
  
  if x==BP[n]:
    return(P[n])
  elif x==1:
    return(0)
  elif x == BP[n-1]+2:
    return(P[n-1]+1)
  elif x <= BP[n-1]+1:
    return(check_P_num(n-1, x-1))
  else:
    return(check_P_num(n-1, x-BP[n-1]-2)+P[n-1]+1)
  
  
print(check_P_num(n, x))