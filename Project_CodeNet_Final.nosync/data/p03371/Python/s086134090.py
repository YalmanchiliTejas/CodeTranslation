def main():
    a, b, c, x, y = map(int, input().split())

    total_min = a * x + b * y

    for i in range(2, max(x, y)*2+1, 2):
        total = a * max(x - i//2, 0) + b * max(y - i//2, 0) + c * i
        total_min = min(total, total_min)
    print(total_min)

if __name__ == "__main__":
    main()