N = int(input())
H = [int(i) for i in input().split()]
#print(N,H)
cnt = 0
hmax = 0
for h in H:
  if hmax <= h:
    cnt += 1
    hmax = h
print(cnt)