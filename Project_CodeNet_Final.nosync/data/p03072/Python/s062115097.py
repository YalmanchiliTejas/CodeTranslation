def main():
    result = sub()
    print(result)


def sub():
    n = int(input())
    heights = [int(x) for x in (input().split())]
    count = 0

    maxHeight = 0
    for index, item in enumerate(heights):
        if item >= maxHeight:
            count = count + 1
            maxHeight = item
    return count


if __name__ == '__main__':
    main()
