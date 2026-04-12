def check_at(i,ans,s):
  if ans[i] == "S":
    if (s[i] == "o" and ans[i-1] != ans[i+1]) or (s[i] == "x" and ans[i-1] == ans[i+1]):
      return True
  else:
    if (s[i] == "o" and ans[i-1] == ans[i+1]) or (s[i] == "x" and ans[i-1] != ans[i+1]):
      return True

N = int(input())
S = input()

opposite = {"S": "W",
            "W": "S"}

for ans in ["SS","SW","WS","WW"]:
  for i in range(1,N-1):
    if ans[i] == "S" and S[i] == "o":
      ans += ans[i-1]
    elif ans[i] == "S" and S[i] == "x":
      ans += opposite[ans[i-1]]
    elif ans[i] == "W" and S[i] == "o":
      ans += opposite[ans[i-1]]
    elif ans[i] == "W" and S[i] == "x":
      ans += ans[i-1]
  
  if (not check_at(-1,ans,S)) and (not check_at(0,ans,S)):
    print(ans)
    break
else:
  print(-1)