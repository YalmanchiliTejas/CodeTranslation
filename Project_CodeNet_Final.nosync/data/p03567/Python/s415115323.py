s = input()
flag = 0
for i in range(len(s)-1):
  if s[i:i+2] == "AC":
    flag = 1
if flag == 1:
  print("Yes")
else:
  print("No")