operator = input().strip()
a, b = 0, 0

for i in operator:
  if i == "A":
    a += 1
  else:
    b += 1
if a == 2:
  print("Yes")
elif b == 2:
  print("Yes")
else:
  print("No")
