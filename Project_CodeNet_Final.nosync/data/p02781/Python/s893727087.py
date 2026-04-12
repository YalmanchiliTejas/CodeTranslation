n=int(input())
k=int(input())
l=len(str(n))
a=(l-1)*(l-2)*(l-3)//6*9**3
if k==2:
  a=(l-1)*(l-2)//2*9*9
elif k==1:
  a=(l-1)*9
sn=list(str(n))
c=0
for i in range(l):
  p=sn[i]
  if p != "0":
    if k-c == 3:
      a+=(l-i-1)*(l-i-2)//2*(int(p)-1)*9*9
    elif k-c == 2:
      a+=(l-i-1)*(int(p)-1)*9
      if not k==2:
        a+=(l-i-1)*(l-i-2)//2*9*9
    elif k-c == 1:
      a+=int(p)
      if not k==1:
        a+=(l-i-1)*9
    c+=1
    if c==k:
      break
print(a)
