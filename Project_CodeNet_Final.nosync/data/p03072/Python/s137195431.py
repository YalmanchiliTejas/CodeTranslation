n=int(input())
h=list(map(int,input().split()))
cnt=1
if n>=2:
  for i in range(1,n):
    if all(h[i]>=h[j] for j in range(i)):
      cnt+=1
  print(cnt)
else:
  print(1)
