s=input()
a=0
b=0
for i in s:
  if i=="A":
    a+=1
  elif i=="B":
    b+=1
if (a+b)!=3 or (a==0 or b==0):
  print("No")
else:
  print("Yes")