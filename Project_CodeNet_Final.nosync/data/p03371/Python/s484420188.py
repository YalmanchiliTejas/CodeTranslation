a, b, c, x, y = map(int, input().split())

set_ga_otoku = c * 2 < a + b
nimai_ga_otoku_a = c * 2 < a
nimai_ga_otoku_b = c * 2 < b

dup = min(x, y)
cost = c * 2 * dup if set_ga_otoku else a * dup + b * dup

x, y = map(lambda x: x - dup, [x, y])

if x:
    cost += c * 2 * x if nimai_ga_otoku_a else a * x
else:
    cost += c * 2 * y if nimai_ga_otoku_b else b * y

print(cost)
