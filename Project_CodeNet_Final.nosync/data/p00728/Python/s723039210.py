import math
while True:
    n = int(input())
    if n == 0 :
        break
    sum = []
    for i in range(n):
        x = int(input())
        sum.append(x)
    sum.sort()
    del sum[n-1]
    del sum[0]
    rsum = 0
    for i in range(n-2):
        rsum = rsum + sum[i]
    average = rsum/(n-2)
    result = math.floor(average)
    print(result)
    
