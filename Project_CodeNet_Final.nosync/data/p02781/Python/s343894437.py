def ans(n,k):
  s=str(n)
  a=len(s)
  b=int(s[0])
  if(n==0):
    return 0
  elif(k==1):
    return 9*(a-1)+b
  elif(k==2):
    return int(81*(a-1)*(a-2)/2)+9*(b-1)*(a-1)+ans(n-b*10**(a-1),1)
  else:
    return int(729*(a-1)*(a-2)*(a-3)/6)+int(81*(b-1)*(a-1)*(a-2)/2)+ans(n-b*10**(a-1),2)

N=int(input())
K=int(input())
print(ans(N,K))