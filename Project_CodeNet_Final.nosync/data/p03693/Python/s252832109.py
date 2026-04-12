def func(a, b ,c):
    number = int(a + b + c)
    result = 'YES' if number % 4 == 0 else 'NO'
    return result

r, g, b = input().split()

print(func(r,  g, b))
