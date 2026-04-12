N=int(input())
s=[int(i) for i in input().split()]
ans=0
for c in range(1,N):
  k=0
  Score=0
  while k*c<N-1:
    a=N-1-k*c
    if ((N-1)%c==0 and k*c>=a) or a<=c:
      break
    Score+=s[k*c]+s[a]
    #print(c,k,Score)
    ans=max(Score,ans)
    k+=1
print(ans)