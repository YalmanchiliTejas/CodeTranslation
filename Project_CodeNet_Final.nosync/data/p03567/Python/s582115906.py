s=str(input())
temp=0
for i in range(len(s)):
  if s[i]=="A" and i<=len(s)-2:
    if s[i+1]=="C":
      temp=1
if temp==1:
  print("Yes")
else:
  print("No")