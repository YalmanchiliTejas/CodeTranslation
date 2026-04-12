N=int(input())
H = list(map(int,input().split()))
ans = H[0]
count=0
for i in range(0,N):
  if ans <= H[i]:
    count+=1
    ans=H[i]
  else:
    continue
print(count)
    