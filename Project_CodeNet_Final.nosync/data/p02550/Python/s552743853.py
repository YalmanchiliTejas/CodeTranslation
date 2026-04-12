

def main():
    n, x, m = map(int, input().split())
    mflg = [-1] * m
    mflg[x] = 0
    ltot = [x]

    tot = x
    a = x
    for i in range(1, n):
        a = a ** 2 % m

        if mflg[a] >= 0:
            b = mflg[a]
            z = (n - i) // (i - b)
            y = (n - i) % (i - b)
            if b == 0 and y == 0:
                tot += ltot[i - 1] * z
            elif b == 0:
                tot += ltot[b - 1 + y] + ltot[i - 1] * z
            else:
                tot += (ltot[b - 1 + y] - ltot[b - 1]) + (ltot[i - 1] - ltot[b - 1]) * z
            break

        mflg[a] = i
        tot += a
        ltot.append(tot)

    print(tot)


main()

