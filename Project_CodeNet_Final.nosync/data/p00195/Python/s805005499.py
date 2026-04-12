s = ["A", "B", "C", "D", "E"]
while True:
  a, b = map(int, input().split())
  if a == 0 and b == 0:
    break
  else:
    m = [0 for i in range(5)]
    m[0] = a + b
    for i in range(1, 5):
      aa, bb = map(int, input().split())
      m[i] = aa + bb
    ans = 0
    mm = 0
    for i in range(5):
      if m[i] > mm:
        mm = m[i]
        ans = i
    print(s[ans], mm)
