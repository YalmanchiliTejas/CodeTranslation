def main():
    N = int(input())
    prices = N * 800
    discount = (N // 15) * 200
    print(prices - discount)

if __name__ == '__main__':
    main()