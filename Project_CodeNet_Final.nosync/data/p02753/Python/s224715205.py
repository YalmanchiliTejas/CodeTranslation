S = input()
A = False
B = False

for s in S:
  if s == "A":
    A = True
  else:
    B = True

if A == True and B == True:
  print("Yes")
else:
  print("No")
