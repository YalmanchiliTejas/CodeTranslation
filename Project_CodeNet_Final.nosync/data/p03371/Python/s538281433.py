#!/usr/bin/env python3

A, B, C, X, Y = map(int, input().split())

# ABセット(ABピザ2枚)をi個購入したとき、
# Aをmax(0, X-i)個買い増す必要があり、Bをmax(0, Y-i)個買い増す必要がある。
# 0 <= i <= 10^5 について、全探索し、最小値を求めればよい

price_min = 5000 * 2 * 100000
for i in range(0, 100000+1):
    price = 2*C*i + A * max(0, X-i) + B * max(0, Y-i)
    if price < price_min:
        price_min = price

print(price_min)
