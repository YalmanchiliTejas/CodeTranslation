x, y, z = map(int, input().split())

i = 0
now = 0

if x < y:
    print("0")
    exit(0)

while True:
    i += 1

    now = y * i + z * (i + 1)
    if now > x:
        print(i - 1)
        break
        
