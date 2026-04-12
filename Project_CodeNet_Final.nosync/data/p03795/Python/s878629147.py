# 055_a
N = int(input())
if 1 <= N & N <= 100:
    count = int(N / 15)
    x = 800 * N
    y = 200 * count
    print(x - y)