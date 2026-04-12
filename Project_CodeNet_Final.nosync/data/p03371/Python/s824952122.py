line = input()
a, b, c, x, y = map(int, line.split(' '))

if x < y:
    pizza = [(x, a), (y, b)]
else:
    pizza = [(y, b), (x, a)]

values = list()
values.append(c * 2 * pizza[0][0] + pizza[1][1] * (pizza[1][0] - pizza[0][0]))
values.append(c * 2 * pizza[1][0])
values.append(a * x + b * y)

print(min(values))
