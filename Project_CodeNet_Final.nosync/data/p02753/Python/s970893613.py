s = list(input())
a, b = 0, 0
a = s.count('A')
b = s.count('B')

if a > 0 and b > 0:
    print('Yes')
else:
    print('No')