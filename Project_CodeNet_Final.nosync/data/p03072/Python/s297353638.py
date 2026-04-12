
n = int(input())
h = list(map(int,input().split()))
cnt = 1
hi = h[0]
for i in range(1,n):
  hi = max(hi,h[i])
  if h[i] >= hi:
    cnt += 1

print(cnt)