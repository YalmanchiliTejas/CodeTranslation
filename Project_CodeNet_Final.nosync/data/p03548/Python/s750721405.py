x,y,z = list(map(int,input().split()))
counter = 0
while True:
    x -= (y+z)
    if x  - z< 0:
        break
    else:
        counter += 1
print(counter)