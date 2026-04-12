a, b, c = map(int, input().split())
d = a - c
e = 0
while True:
    if d >= (b + c):
        d = d - (b + c)
        e += 1
    else:
        break
print(e)
