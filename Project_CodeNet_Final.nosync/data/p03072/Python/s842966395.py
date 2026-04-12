N = map(int, input())
H = list(map(int, input().split(" ")))

HS = sorted(H)

cnt = 0
hsmin = HS[0]
for h in H:
  if h >= hsmin:
    cnt += 1
    hsmin = h
print(cnt)