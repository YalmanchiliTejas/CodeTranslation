a = [input() for i in range(3)]
t = a[1][int(a[2]) - 1]
for c in a[1]:
    print(c if c == t else '*', end='')
