s = input()
flaga = 0
flagb = 0
for i in s:
  if i == "A":
    flaga = 1
  elif i == "B":
    flagb = 1
flag = flaga + flagb
if flag == 2:
  print("Yes")
else:
  print("No")