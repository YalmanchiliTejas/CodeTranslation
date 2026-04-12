cnt = 1
N = int(input())
H = list(map(int, input().split(' ')))
for i in range(1,N,1):
  _cnt=0
  for j in range(0,i,1):
    if H[i]>=H[j]:
      _cnt+=1
  if _cnt==i:
    cnt+=1
print(cnt)