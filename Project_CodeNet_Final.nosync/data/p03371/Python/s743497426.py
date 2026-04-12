input_conditions = input().split()

price_a = int(input_conditions[0])
price_b = int(input_conditions[1])
price_ab = int(input_conditions[2])
required_a = int(input_conditions[3])
required_b = int(input_conditions[4])

price_1 = price_a * required_a + price_b * required_b

if required_a > required_b:
    price_2 = price_ab * required_b * 2 + price_a * (required_a - required_b)
else:
    price_2 = price_ab * required_a * 2 + price_b * (required_b - required_a)

price_3 = price_ab * max(required_a, required_b) * 2

print(min(price_1, price_2, price_3))
