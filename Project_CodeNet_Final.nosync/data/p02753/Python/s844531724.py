input_line = input("")
a_num = 0
b_num = 0
for c in input_line:
  if c == "A":
    a_num += 1
  else:
    b_num += 1

if a_num*b_num > 0:
  print("Yes")
else:
  print("No")