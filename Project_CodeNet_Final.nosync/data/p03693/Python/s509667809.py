# coding: utf-8
# Your code here!

# r, g, b = map(int, input().split())
r, g, b = input().split()

# print(r)
# print(g)
# print(b)

# print(int(r + g + b))

if int(r + g + b) % 4 == 0:
    print('YES')
else:
    print('NO')