N = int(input())
H = list(map(int,input().split()))
Hmax=H[0]
cnt = 1

for i in range(1,N):
  if Hmax<=H[i]:
    cnt += 1
    Hmax = max(Hmax,H[i])
    
print(cnt)