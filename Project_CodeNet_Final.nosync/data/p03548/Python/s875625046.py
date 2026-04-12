def solve():
    x, y, z = list(map(int, input().split(" ")))

    if (x % (y + z) == 0):
        ans = x // (y + z) - 1
    else:
        if (x % (y + z)) >= z:
            ans = x // (y + z)
        else:
            ans = x // (y + z) - 1

    print(ans)
    

solve()