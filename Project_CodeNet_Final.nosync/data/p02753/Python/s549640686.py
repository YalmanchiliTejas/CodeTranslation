s = str(input())
a = 0
for i in s:
  if i == "A":
    a += 1
  elif i == "B":
    a -= 1
if a == 3 or a == -3:
  print("No")
else:
  print("Yes")