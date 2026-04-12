import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N,X = map(int,input().split())
memo = {}
memo[(1,1)] = 1
def cost(N,X):
 L=2**(N+1)-3
 ans=0
 if X==1:
  ans=0
 elif X==2**(N+1)-3:
  ans=2**N-1
 elif X==(L+1)//2:
  if (N-1,X-2) in memo:
   ans=memo[(N-1,X-2)]+1
  else:
   ans=cost(N-1,X-2)+1
 elif X>(L+1)//2:
  if (N-1,X-((L+1)//2)) in memo:
   ans=2**(N-1)+memo[(N-1,X-((L+1)//2))]
  else:
   ans=2**(N-1)+cost(N-1,X-((L+1)//2))
 else:
  if (N-1,X-1) in memo:
   ans=memo[(N-1,X-1)]
  else:
   ans=cost(N-1,X-1)
 memo[(N,X)]=ans
 return ans
print(cost(N+1,X))