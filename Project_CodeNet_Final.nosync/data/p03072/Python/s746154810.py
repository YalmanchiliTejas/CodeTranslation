N = int(input())
tmp = input().split()
H = []
for i in range(len(tmp)):
  H.append(int(tmp[i]))

ans = 0
for i in range(len(H)):
  chkflg = True
  if i >= 1:
    for j in range(i): 
      if H[j] > H[i]:
        chkflg = False
        break

  if chkflg: ans += 1

print(ans)   

