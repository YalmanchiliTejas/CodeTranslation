x, y, z = map(int,input().split())

i = 0
a = a = y * i + z * (i + 1)

while x >= a :
    i += 1
    a = y * i + z * (i + 1)
print('{}'.format(i-1))

