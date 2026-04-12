N = int(input())
H = list(map(int, input().split()))

cnt = 1

for i in range(1, N):
  flag = True
  for h in range(i):
    if H[h] > H[i]:
      flag = False
      break
  if flag:
    cnt += 1

print(cnt)