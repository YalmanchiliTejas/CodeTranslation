n = int(input())
hs = list(map(int, input().split()))

count = 0
v_max = 0

for h in hs:
  if v_max <=h:
    count += 1
    v_max = h
print(count)