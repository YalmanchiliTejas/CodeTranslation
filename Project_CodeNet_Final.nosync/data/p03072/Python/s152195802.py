N = int(input())
H = [int(i) for i in input().split()]
m = 0
b = 0
for a in H:
  if b <= a:
    m += 1
  b = max(b,a)
print(m)