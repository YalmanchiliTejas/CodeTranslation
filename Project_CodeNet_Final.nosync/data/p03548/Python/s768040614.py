x,y,z = map(int,input().split())
n = x//(y+z)
while (n+1)*z + n*y > x:
    n= n-1
print(n)