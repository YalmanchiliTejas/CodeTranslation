def actual(r, g, b):
    num = int(r+g+b)

    if num % 4 == 0:
        return 'YES'
    else:
        return 'NO'


r, g, b = [x for x in input().split()]

print(actual(r, g, b))
