a = input()

for i in range(3):
  if i == 2:
    break
  elif a[i] != a[i+1]:
    break

if i == 2:
  print("No")
else:
  print("Yes")