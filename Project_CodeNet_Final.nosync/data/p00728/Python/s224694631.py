while True:
    A = int(int(input()))
    if A == 0:
        break
    a = [int(input()) for i in range(A)]

    x = min(a)
    y = max(a)
    z = (sum(a) - x - y)//(A-2)

    print(z)
