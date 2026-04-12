def main():
    a_price, b_price, ab_price, a_num, b_num = map(int, input().split())
    chukan_price = (a_price + b_price) / 2
    min_num = min(a_num, b_num)

    ans = 0

    if chukan_price > ab_price:
        ans += min_num * 2 * ab_price
        a_num -= min_num
        b_num -= min_num
        # print(ans, a_num, b_num)
        if a_price > 2 * ab_price:
            ans += a_num * 2 * ab_price
        else:
            ans += a_num * a_price
        if b_price > 2 * ab_price:
            ans += b_num * 2 * ab_price
        else:
            ans += b_num * b_price
    else:
        ans += a_num * a_price
        ans += b_num * b_price

    print(ans)


if __name__ == '__main__':
    main()
