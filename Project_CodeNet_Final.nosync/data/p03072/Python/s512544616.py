def can_view(s):
  t = s[-1]
  for h in s[:-1]:
    if h > t:
      return False
  return True

c = int(input())
hs = list(map(int, input().split(" ")))
a = 0
for i in range(c):
  if can_view(hs[:i+1]):
    a+=1
print(a)

