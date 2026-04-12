def func(a, b ,c):
    number = a + b + c
    result = 'YES' if int(number) % 4 == 0 else 'NO'
    return result

r, g, b = input().split()

print(func(r,  g, b))