#!/usr/bin/python3

def main():
    N = int(input())
    height = list(map(int, input().split()))

    count = 0
    for i, h in enumerate(height):
        if i == 0:
            count += 1
        elif max(height[:i]) <= h:
            count += 1

    print(count)


if __name__ == '__main__':
    main()
