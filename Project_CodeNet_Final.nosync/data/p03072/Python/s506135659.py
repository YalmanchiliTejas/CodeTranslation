N = input().split()
H = map(int, input().split())

n = 0
highest = 0
for h in H:
  if highest <= h:
    n += 1
    highest = h
print(n)