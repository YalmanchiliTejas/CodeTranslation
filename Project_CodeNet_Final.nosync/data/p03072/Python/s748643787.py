n = int(input())
h = [int(i) for i in input().split()]
x = 1
cnt = 1
mx = h[0]
while x < n:
  if h[x] >= mx:
    cnt += 1
    mx = h[x]
  x += 1
print(cnt)