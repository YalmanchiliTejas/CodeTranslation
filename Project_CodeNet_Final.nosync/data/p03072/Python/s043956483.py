N=int(input())
H = list(map(int, input().split()))

res=0
for i in range(N):
  flg=True
  for j in range(i):
    if H[j]>H[i]:
      flg=False
  if flg:
    res+=1

print(int(res))
    