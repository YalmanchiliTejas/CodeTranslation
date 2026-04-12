def main():
    A, B, C, X, Y = map(int, input().split())
    ans = 10**10
    max_c = max(X, Y) + 1
    for i in range(max_c):
        num_c = i * 2
        num_a = max(0, X - i)
        num_b = max(0, Y - i)
        price = num_a * A + num_b * B + num_c * C
        ans = min(price, ans)
    print(ans)

if __name__ == '__main__':
    main()
