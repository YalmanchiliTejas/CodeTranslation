N = int(input())
S = input()

opposite = {"S": "W",
            "W": "S"}

for ans in ["SS","SW","WS","WW"]:
  for i in range(1,N-1):
    if (ans[i],S[i]) in [("S","o"),("W","x")]:
      ans += ans[i-1]
    elif (ans[i],S[i]) in [("S","x"),("W","o")]:
      ans += opposite[ans[i-1]]
  
  for i in [-1,0]:
    if ans[i] == "S":
      if (S[i] == "o" and ans[i-1] != ans[i+1]) or (S[i] == "x" and ans[i-1] == ans[i+1]):
        break
    else:
      if (S[i] == "o" and ans[i-1] == ans[i+1]) or (S[i] == "x" and ans[i-1] != ans[i+1]):
        break
  else:
    print(ans)
    break
else:
  print(-1)