a, b, c = map(int, input().split())
p = 0
for i in range(a):
  if (b + c) * i + c <= a:
    p = i
  else:
    break
print(p)