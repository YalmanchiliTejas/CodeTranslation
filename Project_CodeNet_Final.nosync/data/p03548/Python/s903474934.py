def solve():
    X, Y, Z = map(int, input().split())
    print((X - Z) // (Y + Z))


if __name__ == "__main__":
    solve()