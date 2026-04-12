while True:
    n = int(raw_input())
    if n == 0: break

    ls = [int(raw_input()) for i in range(n)]
    ls.sort()
    print sum(ls[1:-1]) / (n-2)
