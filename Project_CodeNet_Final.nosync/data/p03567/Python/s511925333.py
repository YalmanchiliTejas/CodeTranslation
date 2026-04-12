a=input()
flag=0
for i in range(len(a)-1):
  if a[i:i+2]=="AC":
    flag=1
    break
print("Yes" if flag==1 else "No")