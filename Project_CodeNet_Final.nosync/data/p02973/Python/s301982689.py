n=int(input())
x=[int(input())]
for i in range(n-1):
  a=int(input())
  if x[-1]>=a:
    x+=[a]
  else:
    low=0
    high=len(x)-1
    mid=(high+low)//2
    while high-low>1:
      if x[mid]<a:
        high=mid
      else:
        low=mid
      mid=(high+low)//2
    if x[mid]<a:
      x[mid]=a
    else:
      x[high]=a
print(len(x))