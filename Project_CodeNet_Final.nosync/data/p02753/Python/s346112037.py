S = input()
ans = 0
for i in range(3):
  if S[i] == "A":
    ans += 1

if ans == 3 or ans == 0:
  print("No")
else:
  print("Yes")