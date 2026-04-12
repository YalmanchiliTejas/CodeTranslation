s=list(input())
cnt=0
for i in range(3):
  if s[i]=='A':
    cnt+=1
if cnt==0 or cnt==3:
  print("No")
else:
  print("Yes")