s = input()
str = list(s)
 
ca = str.count("A")
cb = str.count("B")
 
if ca == 3 or cb == 3:
  print("No")
else:
  print("Yes")