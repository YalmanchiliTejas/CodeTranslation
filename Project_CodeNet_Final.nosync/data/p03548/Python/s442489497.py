x,y,z = map(int,input().split())

for i in range(1000000000000000):
    if (x - y*i - (i+1)*z) < 0:
        print(i-1)
        break