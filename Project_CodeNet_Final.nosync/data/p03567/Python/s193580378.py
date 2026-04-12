S = input()
f = 0
for i in range(len(S)-1):
  if S[i] == "A" and S[i+1] == "C":
    f = 1
    break
if f == 0:
  print("No")
else:
  print("Yes")