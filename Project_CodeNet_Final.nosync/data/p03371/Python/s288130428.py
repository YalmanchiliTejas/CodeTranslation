
url = "https://atcoder.jp//contests/abc095/tasks/arc096_a"

def main():
    A, B, C, X, Y = list(map(int, input().split()))
    piza = [X, Y]
    price = 0
    if A + B > C * 2:
        min_piza = min(X, Y)
        price += min_piza * (C * 2)
        piza = [v - min_piza for v in piza]
    # A
    if A > C * 2:
        price += piza[0] * (C * 2)
        piza[1] -= piza[0]
    else:
        price += piza[0] * A
    # B
    if B > C * 2:
        price += piza[1] * (C * 2)
    else:
        price += piza[1] * B
    print(price)


if __name__ == '__main__':
    main()
