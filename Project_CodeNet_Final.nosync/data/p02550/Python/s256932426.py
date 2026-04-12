n,x,m=map(int, input().split())
alist=[]
blist=[0]*m
num=x%m
while blist[num]==0:
  alist.append(num)
  blist[num]=1
  num=(num**2)%m
num1=alist.index(num)
num2=len(alist)
if x==1:
  print(n)
elif n<=num1:
  print(sum(alist[0:n]))
else:
  cycle=(n-num1)//(num2-num1)
  print(sum(alist[0:num1])+cycle*sum(alist[num1:num2+1])+sum(alist[num1:n-cycle*(num2-num1)]))