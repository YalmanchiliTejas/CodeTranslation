x, y, z = map(int, input().split())

n = 1

while True:
    if y * n + z * (n+1) <= x:
        n += 1
    else:
        print(n-1)
        break