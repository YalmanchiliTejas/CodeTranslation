nx = list(map(int, input().split()))
n = nx[0]
x = nx[1]
p = 0
for i in range(n):
    l_thick = 2 ** (n - i + 1) - 3
    if x == 1:
        break
    elif x <= l_thick:
        x = x - 1
    elif x == l_thick + 1 :
        p += 2 ** (n - i) - 1
        break
    elif x <= l_thick * 2 + 1:
        x = x - l_thick - 2
        p += 2 ** (n - i)
    else:
        p += 2 * (2 ** (n - i) - 1) + 1
        break
print(p)