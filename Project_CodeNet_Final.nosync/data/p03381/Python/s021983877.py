n=int(input())
x=list(map(int,input().split()))
xx=sorted(x)
for i in range(n):
 print(xx[n//2] if x[i]<=xx[n//2-1] else xx[n//2-1])