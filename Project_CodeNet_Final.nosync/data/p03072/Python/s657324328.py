n = int(input())
h = list(map(int, input().split()))
h_max = h[0]
cnt = 1
for hi in h[1:]:
  if hi >= h_max:
    h_max = hi
    cnt += 1
print(cnt)
