N = int(input())
ST = input()

# n=1,Nが(S,S)(S,W)(W,S)(W,W)の4通りを仮定してずらずら決めていけばよいはず
# S=0, W=1として, 1-xで切り替える
# 最後に矛盾が生じないやつだけえらぶO(1)で判定できそうだけど。。

pat = [(0,0),(0,1),(1,0),(1,1)]
fl = False

for p in pat:
  ans = []
  x_now = p[0]
  x_prev = p[1]
  ans.append(x_now)
  for i in range(N):
    if ST[i] == 'o':
      if x_now == 0:
        x_next = x_prev
      else:
        x_next = 1 - x_prev
    else:
      if x_now == 0:
        x_next = 1 - x_prev
      else:
        x_next = x_prev
  
    #print(i, ST[i], x_prev, x_now, x_next)
    ans.append(x_next)
    x_prev, x_now = x_now, x_next

  #if ans[-1] == ans[0]:
  if ans[-2] == p[1] and ans[-1] == ans[0]:
    #correct case
    fl = True
    #print(ans)
    break

if fl:
  for i in range(N):
    print("S" if ans[i] == 0 else "W", end="")
  print()
else:
  print("-1")
  