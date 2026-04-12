#! /usr/bin/env python3

a, b, c, x, y = map(int, input().split())

ab_max_pairs = max(x, y)

price_min = 1000000000

for i in range(ab_max_pairs + 1):
    price = c * i * 2 + max(0, (x-i)) * a + max(0, (y-i)) * b
    if price < price_min:
        price_min = price

print(price_min)
