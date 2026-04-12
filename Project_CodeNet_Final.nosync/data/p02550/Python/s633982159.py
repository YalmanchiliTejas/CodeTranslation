n, x, m = [int(i) for i in input().split(" ")]

vis = [-1] * m
sq = [(i*i)%m for i in range(m)]

cur = x
y = x
flag = False
for i in range(n):
  if vis[cur] >= 0:
    flag = True
    break
  vis[cur] = i
  cur = (cur*cur)%m

cycle = max(vis) - vis[cur] + 1

ans = 0
if not flag:
  for i in range(n):
    ans += y
    y = (y*y)%m
    # print("hi")
  print(ans)
elif n <= vis[cur]:
  for i in range(min(n, vis[cur])):
    ans += x
    x = (x*x)%m
  # print("hi")
  print(ans)
else:
  for i in range(min(n, vis[cur])):
    ans += x
    x = (x*x)%m
  y = x
  rem = n - vis[cur]
  cyclesum = 0
  for i in range(cycle):
    cyclesum += y
    y = (y*y)%m
  total = rem//cycle
  extra = rem - cycle*total
  ans += cyclesum*total
  # print("cyclesum", cyclesum)
  for i in range(extra):
    ans += y
    y = (y*y)%m
  print(ans)