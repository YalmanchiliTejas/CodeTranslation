n = int(input())
counter = 1
l = list(map(int, input().split()))
max = l[0]
for a in l[1:]:
  if a >= max:
    max = a
    counter += 1
print(counter)