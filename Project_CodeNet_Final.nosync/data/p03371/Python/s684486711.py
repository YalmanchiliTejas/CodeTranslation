A, B, C, X, Y = [int(x) for x in input().split()]

def main():
    base = min(X, Y)
    rest = max(X, Y) - base
    is_x = X > Y

    base_price = min(A + B, 2 * C) * base
    rest_price = min((A if is_x else B), 2 * C) * rest

    print(base_price + rest_price)

if __name__ == "__main__":
    main()