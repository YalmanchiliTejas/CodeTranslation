x,y,z=map(int,input().split())
x=x-y-2*z
for i in range(50000):
    x=x-y-z
    if x<0:
        print(i+1)
        break