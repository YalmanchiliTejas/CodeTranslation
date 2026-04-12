N = int(input())
H = [int(x) for x in input().split()]
cnt = 0
mh = H[0]
for h in H:
  cnt += 1 if h >= mh else 0
  mh = max(h, mh)
print(cnt)