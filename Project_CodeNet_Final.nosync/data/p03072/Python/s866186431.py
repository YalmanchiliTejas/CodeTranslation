N=int(input())
H=list(map(int,input().split()))
ans=0
for i in range(N):
  if i==0:
    ans+=1
  else:
    for j in range(i):
      if H[j]<=H[i]:
        continue
      else:
        break
    else:
      ans+=1
print(ans)
