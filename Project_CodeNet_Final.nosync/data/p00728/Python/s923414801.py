while True:
    n = int(input())
    if n == 0:
        break
    sum_ = 0
    max_ = 0
    min_ = 1000
    for i in range(n):
        tmp = int(input())
        sum_ += tmp
        max_ = max(max_, tmp)
        min_ = min(min_, tmp)
    sum_ -= max_
    sum_ -= min_
    print(int(sum_/(n-2)))
