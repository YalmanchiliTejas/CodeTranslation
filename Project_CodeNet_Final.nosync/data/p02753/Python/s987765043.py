string = input()
A_flag, B_flag = False, False
for i in string:
  if (i == "A"):
    A_flag = True
  else:
    B_flag = True
if (A_flag and B_flag):
  print("Yes")
else:
  print("No")