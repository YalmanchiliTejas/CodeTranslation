# coding: utf-8

r, g, b = list(map(int, input().split()))

answer = 'YES' if (r * 100 + g * 10 + b) % 4 == 0 else 'NO'

print(answer)
