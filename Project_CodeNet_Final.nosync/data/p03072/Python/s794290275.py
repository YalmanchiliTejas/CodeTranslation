n = int(input())
hl = list(map(int,input().split()))

max = 0
cnt = 0
for i in range(n):
  if max <= hl[i]:
    cnt += 1
    max = hl[i]

print(cnt)