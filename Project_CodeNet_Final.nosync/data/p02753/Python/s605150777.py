s = input()
ans = len(set([s[0], s[1], s[2]]))
if ans == 1:
  print("No")
else:
  print("Yes")