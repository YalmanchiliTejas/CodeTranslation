N = int(input())
H = list(map(int,input().split()))
cnt = 1
maxH = H[0]
for i in range(1,N):
  if H[i] >= maxH:
    cnt+=1
    maxH = max(maxH,H[i])
print(cnt)

