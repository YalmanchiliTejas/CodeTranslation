while True:
    P = []
    n = int(input())
    if n == 0:
        exit()
    for i in range(n):
        P.append(int(input()))
    print(sum(sorted(P)[1:-1]) // (n-2))
