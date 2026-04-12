from math import factorial
N=int(input())
K=int(input())
S=list(map(int,str(N)))

def C(n,r):
  if n>=r:
    return factorial(n)//factorial(r)//factorial(n-r)
  else:
    return 0

def D(i,j):
  return C(i,j)*(9**j)

ans=0
l=len(S)
for i in range(l):
  if S[i]!=0:
    ans+=(S[i]-1)*D(l-1,K-1)+D(l-1,K)
    l-=1
    K-=1
  else:
    l-=1
  if K==0:
    ans+=1
    break
    
print(ans)