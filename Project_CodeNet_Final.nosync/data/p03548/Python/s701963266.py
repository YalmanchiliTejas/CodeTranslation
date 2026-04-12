x,y,z = map(int,input().split())
i = z
ans = 0
while i < x:
  i += y+z
  ans += 1
  if i > x:
    ans -= 1
else:
  print(ans)