n = int(input())
a = [int(i) for i in input().split()]
s = sum(a)
x = 0
for i in a:
    b = (i * (s - i)) % (10 ** 9 + 7)
    s -= i
    x += b
    x %= (10 ** 9 + 7)
print(x)