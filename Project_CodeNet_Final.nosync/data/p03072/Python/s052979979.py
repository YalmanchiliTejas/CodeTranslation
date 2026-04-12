n=int(input())
h=[int(i) for i in input().split()]
#print(n,h)

val=h[0]
cnt=1
if n > 1:
  for i in range(1,n):
    if val <= h[i]:
      val=h[i]
      cnt+=1
    
print(cnt)