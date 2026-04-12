x,y,z = list(map(int,input().split()))

x = x 
count = 0
while True:
    x = x - (y + z)
    if x < z:
        print(count)
        break
    else:
        count += 1
        