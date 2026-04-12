h,w = map(int,input().split())
ans = []
n = h
for i in range(h):
  s = input()
  if("#" in s):
    ans.append(s)
  else:
    n -= 1
i = 0
j = w-1
while True:
  if(i > j):
    break
  flg = True
  for k in range(n):
    if(ans[k][i] == "#"):
      flg = False
      break
  if(flg):
    for k in range(n):
      ans[k] = ans[k][:i] + ans[k][i+1:]
    j -= 1
  else:
    i += 1
for i in ans:
  print(i)