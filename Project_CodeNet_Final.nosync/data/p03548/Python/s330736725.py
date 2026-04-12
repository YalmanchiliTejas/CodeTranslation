x,y,z=map(int,input().split())
for i in range(100001):
    if (z+y)*i+z>x:
        print(i-1)
        break
        