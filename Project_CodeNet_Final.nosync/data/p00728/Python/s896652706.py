while True:
    n = int(input())
    if n == 0:
        break
    s = sorted([int(input()) for i in range(n)])
    s = s[1:-1]
    print(sum(s)//len(s))
