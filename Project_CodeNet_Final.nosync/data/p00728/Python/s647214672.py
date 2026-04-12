while True:
    n = int(input())
    if not n:
        break
    data = [int(input()) for i in range(n)]
    data.sort()
    print int(sum(data[1:-1]) / (n - 2))