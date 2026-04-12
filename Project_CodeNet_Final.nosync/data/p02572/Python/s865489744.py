N=int(input())
A=list(map(int,input().split()))
x=0
x=sum(A)**2
for i in A:
  x-=i**2
print(x//2%1000000007)