N = int(input())
Hs = [int(i) for i in input().split()]

max_height = 0
count = 0
for H in Hs:
  if max_height <= H:
    count += 1
    max_height = H
print(count)