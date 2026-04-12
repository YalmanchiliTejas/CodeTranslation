k, a, b = map(int, input().split())
k = max(0, k - a)
if k > 0 and a <= b:
  print(-1)
elif a == b:
  print(1)
else:
  print((k // (a - b) + int(k % (a - b) != 0)) * 2 + 1)