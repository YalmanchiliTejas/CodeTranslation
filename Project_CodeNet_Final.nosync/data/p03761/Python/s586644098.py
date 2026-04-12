n = int(input())
l = []
ans = ""
for i in range(n):
  l.append(input())
for i in range(97, 123):
  count = 0
  minimum = float('inf')
  for j in l:
    temp = j.count(chr(i))
    if temp >= 1:
      minimum = min(minimum, temp)
      count += 1
  if count == n:
    ans += chr(i)*minimum

print(ans)