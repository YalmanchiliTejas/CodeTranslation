s = input()

s = dict.fromkeys(list(s))

if len(s) == 1:
  print("No")
else:
  print("Yes")