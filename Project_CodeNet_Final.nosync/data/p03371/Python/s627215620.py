def main():
    a, b, c, x, y = map(int, input().split())

    total_min = a * x + b * y

    for i in range(1, max(x, y)+1):
        total = a * max(x - i, 0) + b * max(y - i, 0) + c * i * 2
        total_min = min(total, total_min)
    print(total_min)

if __name__ == "__main__":
    main()