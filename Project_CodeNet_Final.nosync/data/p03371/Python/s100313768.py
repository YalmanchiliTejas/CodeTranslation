def main():
    a, b, ab, x, y = map(int, input().split())
    # abをx枚買うかy枚買うか、0枚買うかの3パターン
    ab *= 2
    ab_x = ab * x + b * max((y - x), 0)
    ab_y = ab * y + a * max((x - y), 0)
    ab_0 = a * x + b * y
    print(min(ab_x, ab_y, ab_0))


if __name__ == "__main__":
    main()
