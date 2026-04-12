while 1:
    n = int(input())
    if n == 0:
        break

    pt = []
    for _ in range(n):
        pt.append(int(input()))

    pt.sort()
    pt.pop(0)
    pt.pop()

    ans = int(sum(pt) / len(pt))
    print(ans)

