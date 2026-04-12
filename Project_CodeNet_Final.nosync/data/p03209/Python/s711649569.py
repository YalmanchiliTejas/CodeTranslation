n, x = map(int, input().split())
bli = []
pli = []
z = 2 ** (n + 2) - 3
count = 0
for i in range(n + 1):
    y = 2 ** (i + 2) - 3
    bli.append(y // 2 + 1)
    pli.append(y // 2)
for i in range(n, -1, -1):
    if x == 0:
        break
    elif i == 0:
        count += 1
        break
    elif x > (2 ** (i + 2) - 3) // 2 + 1:
        count += bli[i - 1] + 1
        x -= (2 ** (i + 2) - 3) // 2
    elif x == (2 ** (i + 2) - 3) // 2 + 1:
        count += bli[i - 1] + 1
        break
    x -= 1
print(count)