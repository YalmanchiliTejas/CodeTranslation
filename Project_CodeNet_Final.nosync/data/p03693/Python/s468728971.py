s = ""
a = list(input().split())
for i in range(3):
  s += a[i]
if eval(s) % 4 == 0:
  print("YES")
else:
  print("NO")