def solve():
    r, g, b = map(int, input().split())
    if (100 * r + 10 * g + b) % 4 == 0:
        ans = "YES"
    else:
        ans = "NO"
    print(ans)

if __name__ == "__main__":
    solve()
