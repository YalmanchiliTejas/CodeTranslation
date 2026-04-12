def read():
    N = int(input())
    As = list(map(int, input().split(' ')))
    return N, As


def func(N, As):
    ans = 0
    s = As[-1]
    for i in range(N - 1):
        t = As[-1 * (i+2)]
        ans += s * t
        s += t
    return ans % (10 ** 9 + 7)

if __name__ == '__main__':
    N, As = read()
    print(func(N, As))
