n = int(input())
a = list(map(int, input().split()))

if n % 2 == 0:
    b = [0] * n
    for i in range(n):
        if i // 2 == 0:
            b[i] = a[i]
        else:
            if i % 2 == 0:
                b[i] = b[i - 2] + a[i]
            else:
                b[i] = max(b[i - 3], b[i - 2]) + a[i]
    print(max(b[-1], b[-2]))
else:
    b = []
    for i in range(2):
        temp = [0] * n
        b.append(temp)
    for i in range(n):
        if i // 2 == 0:
            b[0][i] = a[i]
        else:
            if i % 2 == 1:
                b[0][i] = max(b[0][i - 3], b[0][i - 2]) + a[i]
            else:
                b[0][i] = b[0][i - 2] + a[i]
                if i == 2:
                    b[1][i] = b[1][i - 2] + a[i]
                else:
                    b[1][i] = max(b[0][i - 4], b[0][i - 3], b[1][i - 2]) + a[i]
    print(max(b[1][-1], b[0][-2], b[0][-3]))