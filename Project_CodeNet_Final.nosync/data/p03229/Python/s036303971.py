n=int(input())
l=[]
for i in range(n):
  l.append(int(input()))
l1=sorted(l)
if n%2==0:
  k=n//2
  sum=0
  for i in range(0,k):
    sum-=2*l1[i]
  for i in range(k,n):
    sum+=2*l1[i]
  sum-=l1[k]
  sum+=l1[k-1]
  print(sum)
else:
  k=n//2
  sum=0
  for i in range(k,n):
    sum+=2*l1[i]
  for i in range(k):
    sum-=2*l1[i]
  sum-=l1[k]
  sum-=l1[k+1]
  sum1=0
  for i in range(k+1,n):
    sum1+=2*l1[i]
  for i in range(k+1):
    sum1-=2*l1[i]
  sum1+=l1[k]
  sum1+=l1[k-1]
  print(max(sum,sum1))