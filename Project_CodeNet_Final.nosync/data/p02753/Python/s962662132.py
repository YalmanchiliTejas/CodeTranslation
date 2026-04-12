s=list(input())
flagS = s[0]
flag=0
for i in range(1,3):
  if flagS != s[i]:
    flag+=1
if flag==0:
  print("No")
else:
  print("Yes")