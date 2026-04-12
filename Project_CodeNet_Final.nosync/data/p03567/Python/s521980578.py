S = input()


ans =0
for i in range((len(S)-1)):
  if (S[i] == "A") and (S[i+1] =="C"):
    ans = 1
if ans == 1:
  print("Yes")
else:
  print("No")