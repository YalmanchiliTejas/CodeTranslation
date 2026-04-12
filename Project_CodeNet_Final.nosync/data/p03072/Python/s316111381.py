count = int(input())
m = 0
c = 0
vals = input().split(" ")
for i in vals:
  val = int(i)
  m = max(m, val)
  if val >= m:
    c = c + 1
print(c)