s = input()

flag = True

for i in range(len(s)-1):
  if s[i] == 'A' and s[i+1] == 'C':
    if flag:
      print("Yes")
    flag = False
    
if flag:
  print("No")
    
