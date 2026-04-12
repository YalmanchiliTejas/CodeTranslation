N = input()
H = list(map(int, input().split()))
count = 0
t = H[0]
for h in H:
  if h >= t:
    count += 1
    t = h
print(count)
