from itertools import accumulate


def main():
    n = int(input())
    array = [int(x) for x in input().split()]
    acc = accumulate(array)
    mod = 10 ** 9 + 7
    ans = 0
    for i, ai in enumerate(acc):
        if i == n - 1:
            continue
        ans += ai * array[i + 1]
        ans %= mod
    return ans


if __name__ == '__main__':
    print(main())
