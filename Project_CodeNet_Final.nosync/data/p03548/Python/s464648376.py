x,y,z=map(int,input().split())
n=0
while x>=n*y+(n+1)*z:
    n+=1
print(n-1)