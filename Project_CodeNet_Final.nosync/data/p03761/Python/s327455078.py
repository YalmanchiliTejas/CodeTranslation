n = int(input())
l = [input() for i in range(n)]
ans = ""

for i in range(97, 123):
  now = chr(i)
  temp = []
  for j in l:
    temp.append(j.count(now))
  ans += now*min(temp)
print(ans)