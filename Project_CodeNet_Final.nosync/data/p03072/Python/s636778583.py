N=int(input())
H=list(map(int, input().split()))
ans=0
for i in range(N):
  sea=1
  for j in range(i):
    if H[i]<H[j]:
      sea=0
      break
  ans += sea
print(ans)