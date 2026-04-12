def solve():
    r, g, b = list(map(str, input().split(" ")))
    colors = [r, g, b]
    ans = "".join(colors)
    if int(ans) % 4 == 0:
        print("YES")
    else:
        print("NO")


solve()