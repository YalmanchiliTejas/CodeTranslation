s = [i for i in input()]
s0 = s[0]
for j in s[1:]:
  if s0 != j:
    print("Yes")
    exit()
  s0 = j
print("No")