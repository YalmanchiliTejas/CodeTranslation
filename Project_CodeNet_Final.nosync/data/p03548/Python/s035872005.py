x,y,z = map(int,input().split())

length = x - 2*z

c = 1
while True:
    if (y*c)+(z*(c-1)) > length:
        break
    
    c += 1

print(c-1)