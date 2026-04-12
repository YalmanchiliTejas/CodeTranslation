n = int(input())
k = int(input())
def f(n,k):
  m = len(str(n))
  if n < 10^4:
    s = 0
    for i in range(1,n+1):
      if sum([1 for j in str(i) if j!="0"])==k:
        s += 1
  else:
    if k==1:
      s = n//(10**(m-1)) + 9*(m-1)
    elif k==2:
      s = (n//(10**(m-1))-1)*9*(m-1) + f(n%(10**(m-1)),1) + 9*9*(m-1)*(m-2)//2
    elif k==3:
      s = (n//(10**(m-1))-1)*9*9*(m-1)*(m-2)//2 + f(n%(10**(m-1)),2) + 9*9*9*(m-1)*(m-2)*(m-3)//6
  return s
print(f(n,k))