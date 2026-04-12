def main():
    A, B, AB, X, Y = list(map(int, input().split()))

    min_price = 10**100

    for n_pizza_ab in range(0, 200001, 2):
        short_pizza_a = max(X - n_pizza_ab // 2, 0)
        short_pizza_b = max(Y - n_pizza_ab // 2, 0)

        price = short_pizza_a * A + short_pizza_b * B + n_pizza_ab * AB

        if price < min_price:
            min_price = price

    print(min_price)

main()
