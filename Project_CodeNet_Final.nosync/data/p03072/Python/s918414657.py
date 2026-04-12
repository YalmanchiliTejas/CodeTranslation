N = int(input())
H = list(map(int, input().split()))

m = H[0]
cnt = 0
for h in H:
  if m <= h:
    cnt += 1
    m = h

print(cnt)
