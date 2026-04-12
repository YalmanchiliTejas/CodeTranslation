from bisect import bisect

n, x = map(int, input().split())

P_N = [1]
L_N = [1]

for i in range(n):
  P_N.append(2*P_N[i]+1)
  L_N.append(2*L_N[i]+3)
  
def rec_check(n, x):
  if n==0:
    return(0 if x<=0 else 1)
  
  if x <= L_N[n-1]+1:
    return(rec_check(n-1, x-1))
  else:
    return(P_N[n-1]+1+rec_check(n-1, x-2-L_N[n-1]))
  
print(rec_check(n,x))    
