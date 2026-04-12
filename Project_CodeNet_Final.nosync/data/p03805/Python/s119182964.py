N, M=map(int, input().split())
net=[[0 for i in range(N)] for j in range(N)]

for i in range(M):
  a, b=map(int, input().split())
  a-=1
  b-=1
  net[a][b]=1
  net[b][a]=1
  
def f(N):
  nums=[i for i in range(1, N)]
  out=g([0], nums)
  return out

def g(order, nums):
  k=len(nums)
  if k==1:
    return [order+nums]
  else:
    out=[]
    for i in range(k-1):
      temp=g(order+[nums[i]], nums[:i]+nums[i+1:])
      out+=temp
    temp=g(order+[nums[-1]], nums[:-1])
    out+=temp
    return out
  
orderlists=f(N)
counter=0
for orderlist in orderlists:
  k=0
  for i in range(N-1):
    k+=net[orderlist[i]][orderlist[i+1]]
  if k==N-1:
    counter+=1
    
print(counter)