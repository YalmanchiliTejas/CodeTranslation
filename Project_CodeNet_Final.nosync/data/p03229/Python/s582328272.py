n=int(input())
l=[]
for i in range(n):
  l.append(int(input()))
l.sort()
if n%2==0:
  m=n//2
  sum1=0
  sum2=0
  for j in range(m):
    sum1 += l[j]
    sum2 += l[n-1-j]
  max=2*sum2-2*sum1-l[m]+l[m-1]
  print(max)
else:
  if n==3:
    max1=l[2]+l[1]-2*l[0]
    max2=2*l[2]-l[1]-l[0]
    if  (max1>max2):
      print(max1)
    else:
      print(max2)
  else:
    m=(n-1)//2
    sum1=0
    sum2=0
    for j in range(m+1):
      sum1 += l[j]
      sum2 += l[n-1-j]
    max1=2*sum2-l[m]-l[m+1]-2*sum1+2*l[m]
    max2=2*sum2-2*l[m]-2*sum1+l[m]+l[m-1]
    if  (max1>max2):
      print(max1)
    else:
      print(max2)