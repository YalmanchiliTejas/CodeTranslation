s=input();a=0;b=0
for i in range(len(s)) :
  if s[i]=="A" :
    a=a+1
  elif s[i]=="B" :
    b=b+1
if a>0 and b>0 :
  print("Yes")
else :
  print("No")