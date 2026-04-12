s = input()
flag1 = "ng"
flag2 = "ng"
for i in s:
    if flag1 == "ok":
      if i == "C":
        flag2 = "ok"
        break
    if i == "A":
      flag1 = "ok"
    else:
      flag1 = "ng"

if flag2 == "ng":
  print("No")
else:
  print("Yes")