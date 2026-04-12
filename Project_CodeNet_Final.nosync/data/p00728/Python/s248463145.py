import math
while(1):
    n = int(input())
    if (n == 0):
        break
    a = [int(input()) for i in range(n)]

    a.sort()
    del a[0]
    del a[-1]
    sum = 0
    for i in range(n-2):
        sum += a[i]
    sum = math.floor(sum / (n-2))

    print("%d" % sum)