def actual(N):
    amount = 800 * N

    coupon = N // 15

    discount = 200 * coupon

    return amount - discount

N = int(input())
print(actual(N))