n = int(input())
h = list(map(int, input().split()))
cnt = []
max = 0
for i in range(n):
  if h[i] >= max:
    max = h[i]
    cnt.append(h[i])
print(len(cnt))
