while True:
    n = int(input())
    if n == 0:
        break
    point = []
    for i in range(n):
        point.append(int(input()))
    point.sort()
    del point[0]
    del point[-1]
    print(sum(point) // (n - 2))

