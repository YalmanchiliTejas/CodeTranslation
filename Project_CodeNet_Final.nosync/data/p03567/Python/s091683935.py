s= input()
t=0
for i in range(len(s)-1):
  if s[i]+s[i+1]=="AC":
    t +=1
if t>0:
  print("Yes")
else:
  print("No")
