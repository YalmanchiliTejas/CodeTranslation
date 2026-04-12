x,y,z = map(int, input().split())
n = x//(y+z)
if x-n*(y+z) >= z:
    print(n)
else:
    print(n-1)