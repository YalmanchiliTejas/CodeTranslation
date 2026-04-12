input()
c = m = 0
for i in map(int, input().split()):
  if i >= m:
    m = i
    c += 1
print(c)