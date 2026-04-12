global opposite
opposite = {"S": "W",
            "W": "S"}

def generate(ans,s,N):
  global opposite
  for i in range(1,N-1):
    if ans[i] == "S" and s[i] == "o":
      ans += ans[i-1]
    elif ans[i] == "S" and s[i] == "x":
      ans += opposite[ans[i-1]]
    elif ans[i] == "W" and s[i] == "o":
      ans += opposite[ans[i-1]]
    elif ans[i] == "W" and s[i] == "x":
      ans += ans[i-1]
  
  if ans[-1] == "S":
    if (s[-1] == "o" and ans[-2] != ans[0]) or (s[-1] == "x" and ans[-2] == ans[0]):
      return True
  if ans[-1] == "W":
    if (s[-1] == "o" and ans[-2] == ans[0]) or (s[-1] == "x" and ans[-2] != ans[0]):
      return True
  if ans[0] == "S":
    if (s[0] == "o" and ans[-1] != ans[1]) or (s[0] == "x" and ans[-1] == ans[1]):
      return True
  if ans[0] == "W":
    if (s[0] == "o" and ans[-1] == ans[1]) or (s[0] == "x" and ans[-1] != ans[1]):
      return True
  print(ans)

N = int(input())
S = input()
if generate("SS",S,N):
  if generate("SW",S,N):
    if generate("WS",S,N):
      if generate("WW",S,N):
        print(-1)


