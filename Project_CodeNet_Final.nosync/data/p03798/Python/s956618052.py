n = int(input())
s = list(input())
# S = 1 W = -1
ss = [1,1]
sw = [1,-1]
ws = [-1,1]
ww = [-1,-1]
ans = []
for i in range(1,n):
  flag = 1
  if s[i] == "x":
    flag = -1
  if ss[i] == 1:
    ss.append(flag*ss[i-1])
  else:
    ss.append(flag*-ss[i-1])
  if sw[i] == 1:
    sw.append(flag*sw[i-1])
  else:
    sw.append(flag*-sw[i-1])
  if ws[i] == 1:
    ws.append(flag*ws[i-1])
  else:
    ws.append(flag*-ws[i-1])
  if ww[i] == 1:
    ww.append(flag*ww[i-1])
  else:
    ww.append(flag*-ww[i-1])
flag = 1
if s[0] == "x":
  flag = -1
if ss[0] == ss[-1] and ss[1] == ss[0]*flag*ss[-2]:
  ans = ss
elif sw[0] == sw[-1] and sw[1] == sw[0]*flag*sw[-2]:
  ans = sw
elif ws[0] == ws[-1] and ws[1] == ws[0]*flag*ws[-2]:
  ans = ws
elif ww[0] == ww[-1] and ww[1] == ww[0]*flag*ww[-2]:
  ans = ww
if ans == []:
  print(-1)
else:
  ans = ans[:n]
  ans = ["S" if i == 1 else "W" for i in ans]
  print("".join(ans))