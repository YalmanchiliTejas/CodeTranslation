# ans

N = int(input())
H = list(map(int, input().split()))
cnt = 1

for i in range(N):
  flg = False
  for j in range(0, i):
    if H[j] <= H[i]:
      flg = True
    else:
      flg = False
      break
  if flg == True:
    cnt += 1
        
print(cnt)