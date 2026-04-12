S = input()

flag_a = 0
flag_b = 0
for i in range(3):
  if S[i] == "A":
    flag_a += 1
  else:
    flag_b += 1
if flag_a and flag_b:
  print("Yes")
else:
  print("No")