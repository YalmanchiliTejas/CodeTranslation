N = int(input())
S = input()

T = [["S", "S"], ["S", "W"], ["W", "S"], ["W", "W"]]

for t in T:
  for i in range(1, N-1):
    if (t[i] == "S" and S[i] == "o") or (t[i] == "W" and S[i] == "x"):
        t.append(t[i-1])
    else:
        t.append("S" if t[i-1] == "W" else "W")
  #print(t)
  
  flag = 1
  if (t[0] == "S" and S[0] == "o") or (t[0] == "W" and S[0] == "x"):
    if t[-1] != t[1]: flag = 0
  else:
    if t[-1] == t[1]: flag = 0
  if (t[-1] == "S" and S[-1] == "o") or (t[-1] == "W" and S[-1] == "x"):
    if t[-2] != t[0]: flag = 0
  else:
    if t[-2] == t[0]: flag = 0
  if flag:
    print("".join(t))
    exit()
print(-1)