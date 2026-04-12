n = int(input())
h = map(int, input().split())
a = 0
b = 0
for i in h:
  if b <= i:
    b = i
    a += 1
print(a)