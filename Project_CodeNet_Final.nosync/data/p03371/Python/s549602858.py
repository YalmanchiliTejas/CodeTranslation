def main():
    A, B, C, X, Y = map(int, input().split())
    prices = sorted([(X, A, C), (Y, B, C)], key=lambda x: x[0])
    min_price = 1e10
    for i in range(prices[0][0]+1):
        tmp_price = prices[0][1] * i + 2 * prices[0][2] * (prices[0][0]-i)
        rest = prices[1][0] - (prices[0][0]-i)
        tmp_price += min(rest * prices[1][1], 2 * rest * prices[1][2])
        min_price = min(min_price, tmp_price)

    print(min_price)


if __name__ == '__main__':
    main()
