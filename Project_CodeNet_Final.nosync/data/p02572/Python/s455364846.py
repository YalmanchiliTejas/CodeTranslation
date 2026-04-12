def II(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

N=II()
A=LI()
#A.sort()
SA=sum(A)
#print(SA)
AccA=[A[0]]
for i in range(1,N):
  AccA.append(AccA[-1]+A[i])
  
#AccA.reverse()
ans=0
for i in range(N-1):
  ans+=A[i]*(SA-AccA[i])
  ans=ans%(10**9+7)
print(ans)