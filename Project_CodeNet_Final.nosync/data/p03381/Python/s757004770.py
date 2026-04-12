n=int(input())
x=list(map(int,input().split()))
xx=sorted(x)
for i in range(n):
 if x[i]<=xx[n//2-1]:
  print(xx[n//2])
 else:
  print(xx[n//2-1])