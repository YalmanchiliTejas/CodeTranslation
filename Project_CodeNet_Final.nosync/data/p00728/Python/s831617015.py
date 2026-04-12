while True:
    n = int(input())
    if n == 0:
        break

    s = []
    for i in range(n):
        s.append(int(input()))

    s.remove(max(s)); s.remove(min(s))
    print(sum(s)//len(s))

