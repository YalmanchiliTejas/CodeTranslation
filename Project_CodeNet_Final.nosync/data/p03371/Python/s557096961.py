# ABC095C - Half and Half
def main():
    a, b, c, x, y = list(map(int, input().rstrip().split()))
    ans = min(
        c * 2 * max(x, y),
        a * x + b * y,
        c * 2 * y + a * max(0, x - y),
        c * 2 * x + b * max(0, y - x),
    )
    print(ans)


if __name__ == "__main__":
    main()