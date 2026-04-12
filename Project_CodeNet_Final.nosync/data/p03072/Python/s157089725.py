input()
H = list(map(int, input().split()))

max_ = 0
cnt = 0

for h in H:
  if h >= max_:
    cnt += 1
    max_ = h

print(cnt)