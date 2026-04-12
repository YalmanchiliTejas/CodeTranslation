while True:
    n = int(input())
    if not(n): break
    s = sum(sorted([int(input()) for i in range(n)])[1:-1])
    print(s//(n-2))