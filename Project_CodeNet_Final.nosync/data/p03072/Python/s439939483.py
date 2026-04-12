N = int(input())
H = list(map(int, input().split()))

cnt = 1
for i in range(1, N):
  see = True
  for j in range(0, i):
    if H[j] > H[i]:
      see = False
  if see:
    cnt += 1
    
print(cnt)