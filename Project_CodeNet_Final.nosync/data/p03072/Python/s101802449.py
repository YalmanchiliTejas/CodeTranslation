N = int(input())
H = list(map(int, input().split()))

cnt = 1

for i in range (1, N):
  mieru = True
  for j in range (i):
    
    if H[i] < H[j]:
      mieru = False
      break
      
  if mieru == True:
    cnt += 1
    
print(cnt)