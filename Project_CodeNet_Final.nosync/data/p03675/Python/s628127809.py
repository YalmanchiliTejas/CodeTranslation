# -*- coding: utf-8 -*-

# AtCoder Beginner Contest
# Problem C

if __name__ == '__main__':
    n = int(input())
    a = list(map(str, input().split()))
    odd = a[::2]
    even = a[1::2]

    if n % 2 == 0:
        result = even[::-1] + odd
    else:
        result = odd[::-1] + even

    print(' '.join(result))
