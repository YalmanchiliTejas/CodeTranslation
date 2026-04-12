# Align
""" Tenka1 Programmer Beginner Contest C """

test = False
A = []

N = int(input())
for _ in range(N):
    A.append(int(input()))


def answer(n, l):
    """中心が最小"""
    x = 0
    y = 0

    if n == 2:
        return abs(l[0] - l[1])

    if n%2 == 1: # nが奇数の時
        l.sort()
        for i in range(n//2):
            x += 2 * l[-(i+1)]
            x -= 2 * l[i]
        x -= l[n//2]
        x += l[n//2 -1]

        l.sort(reverse=True)
        for i in range(n//2):
            y += 2 * l[-(i+1)]
            y -= 2 * l[i]
        y -= l[n//2]
        y += l[n//2 -1]

        if test:
            print('x =', x)
            print('y =', y)
        return max(x, -y)

    # nが偶数の時
    l.sort()
    for i in range(n//2 -1):
        x += 2 * l[-(i+1)]
        x -= 2 * l[i]
    x += l[n//2]
    x -= l[n//2 -1]

    return x


def main():
    """main"""
    print(answer(N, A))


if __name__ == '__main__':
    main()
