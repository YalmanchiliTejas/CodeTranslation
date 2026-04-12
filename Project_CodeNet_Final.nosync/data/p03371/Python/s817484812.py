def main():
    a, b, c, x, y = map(int, input().split())
    price = {x: a, y: b}
    answer = min(a * x + b * y, max(x, y) * 2 * c, min(x, y) * 2 * c + (max(x, y) - min(x, y)) * price[max(x, y)])
    print(answer)


if __name__ == '__main__':
    main()

