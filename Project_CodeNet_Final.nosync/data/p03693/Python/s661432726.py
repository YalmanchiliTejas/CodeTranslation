a = input()

a = a.split()

r = int(a[0])
g = int(a[1])
b = int(a[2])

number = r * 100 + g * 10 + b

"""
print(a)
print(r)
print(g)
print(b)
print(number)
"""

if number % 4 == 0:
    print("YES")
else:
    print("NO")
