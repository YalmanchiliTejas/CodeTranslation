a=list(input())
count=0
if a[0]!=a[1]:
  count=1
if a[1]!=a[2]:
  count=count+1
if count>=1:
  print("Yes")
else:
  print("No")