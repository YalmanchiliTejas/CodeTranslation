s = input()
a = False
b = False

for c in s:
  if c == 'A':
    a = True
  else:
    b = True

if a and b:
  print("Yes")
else:
  print("No")
