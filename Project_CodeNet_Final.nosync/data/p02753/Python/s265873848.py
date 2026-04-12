s = input()
pre = s[0]
for a in s[1:]:
  if pre != a:
    print("Yes")
    exit()
  pre = a
print("No")