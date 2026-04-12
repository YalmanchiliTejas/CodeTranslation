n = input()
h_list = map(int, input().split())
a = 0
b = 0
for h in h_list:
  if b <= h:
    b = h
    a += 1
print(a)
