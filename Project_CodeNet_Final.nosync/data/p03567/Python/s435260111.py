s=list(input())
s.append("0")
flag=0
for i in range(5):
  if s[i]=="A" and s[i+1]=="C":
    flag=1
    break
  elif s[i]=="0":
    break
if flag==1:
  print("Yes")
else:
  print("No")