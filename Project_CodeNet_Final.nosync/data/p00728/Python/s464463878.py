while True:
    n = int(input())
    max = 0
    min = 1000
    sum = 0
    ave = 0
    if n == 0:
        break
    for i in range(n):
        s = int(input())
        sum += s
        if s < min:
            min = s
        if max < s:
            max = s
    ave = (sum - min - max) // (n - 2)
    print(ave)
