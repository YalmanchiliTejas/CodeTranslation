N, X = map(int, input().split())
p = 1
t = 1
pdic = {}
tdic = {}
for i in range(N):
  pdic[i] = p
  tdic[i] = t
  p = 2*p+1
  t = 2*t+3
pdic[N] = p
tdic[N] = t
ans = 0
nokori = X
state = N
count = N
while True:
  while tdic[count]+state-count>nokori:
    count -= 1
    if count<0:
      break
  if count<0:
    break
  nokori -= (tdic[count]+state-count)
  state = count
  ans += pdic[count]
  if nokori==0:
    break
  nokori -= 1
  ans += 1
  if nokori==0:
    break
print(ans)