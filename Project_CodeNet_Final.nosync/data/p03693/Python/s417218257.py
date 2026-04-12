# -*- coding: utf-8 -*-

# AtCoder Beginner Contest
# Problem A

if __name__ == '__main__':
    colors = list(map(str, input().split()))
    number = int(''.join(colors))

    if number % 4 == 0:
        print('YES')
    else:
        print('NO')
