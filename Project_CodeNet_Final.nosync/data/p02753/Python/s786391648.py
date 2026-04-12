s = input()
x = s[0]
flag = False
for i in range(len(s)):
  if s[i] != x:
    flag = True
    break
if flag == True:
  print("Yes")
else:
  print("No")
