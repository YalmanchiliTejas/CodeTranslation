N=int(input().split()[0])
H=list(map(int, input().split()))

cnt = 0
for i, h in enumerate(H):
  if(max(H[0:i+1]) <= h):
    cnt+=1

print(cnt)
