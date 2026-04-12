S = input()
f = False
for i in range(len(S)-1):
  if S[i:i+2]=="AC":
    f = True
if f:
  print("Yes")
else:
  print("No")