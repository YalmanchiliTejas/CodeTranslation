import math
N=int(input())
x=800*N
y=N//15
if (y+1)*15<=N:
  y+=1
print(x-200*y)