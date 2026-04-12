S = input()
S = list(S)
res = "No"
for i in range(len(S)-1):
  if S[i] + S[i+1] == "AC":
    res = "Yes"
print(res)
    
