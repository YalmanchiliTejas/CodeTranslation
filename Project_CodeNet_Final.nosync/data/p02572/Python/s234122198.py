def main():
    input()  # n
    array = [int(x) for x in input().split()]
    mod = 10 ** 9 + 7
    total = 0
    center_blocks = 0
    for x in array:
        total += x
        center_blocks += x ** 2
    total = total ** 2
    return (total - center_blocks) // 2 % mod


if __name__ == '__main__':
    print(main())
