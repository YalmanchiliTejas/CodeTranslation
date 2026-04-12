def main(n,a):
  b=[-x for x in a]
  b.sort()
  from heapq import heappop,heappush,heapify
  heapify(b)
  ans=-1
  for i in range(n+2):
    v=heappop(b)
    if -v<=n-1:
      ans=i
      break
    b=[x-1 for x in b]
    v+=n
    heappush(b,v)
  if ans>=0:return ans
  suma=sum(a)
  # mod (n+1)で考える
  am=[x%(n+1) for x in a]
  sumam=0
  for i in range(n+1):
    am=[(x+1)%(n+1) for x in am]
    if max(am)<=n-1:
      sumam=max(sum(am),sumam)
  ans=suma-sumam
  return ans


n=int(input())
a=list(map(int,input().split()))
print(main(n,a))
