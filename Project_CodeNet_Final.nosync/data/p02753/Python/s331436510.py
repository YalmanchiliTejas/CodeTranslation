s=input()
t=[]
for i in s:
  t.append(i)
  
if len(set(t))==1:
  print("No")
else:
  print("Yes")