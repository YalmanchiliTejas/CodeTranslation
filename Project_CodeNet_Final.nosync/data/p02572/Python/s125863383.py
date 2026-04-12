import sys


def resolve(in_):
    N = int(next(in_))
    A = tuple(map(int, next(in_).split()))

    mod = 10 ** 9 + 7
    ans = 0
    v = sum(A)
    for a in A:
        v -= a
        ans += a * v
        ans %= mod

    return ans
    

def main():
    answer = resolve(sys.stdin.buffer)
    print(answer)


if __name__ == '__main__':
    main()
