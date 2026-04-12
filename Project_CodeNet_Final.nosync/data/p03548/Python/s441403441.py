x, y, z = map(int, input().split())

p = 50000
while True:
    if x >= (p+1)*z + p*y:
        print(p)
        exit()
    else:
        p -= 1
