n = int(input())
h = [int(i) for i in input().split()]
cnt = 0
for i in range(n):
  if h[i] == max(h[:i+1]):
    cnt += 1
print(cnt)