def main():
    input()
    array = (int(x) for x in input().split())
    mod = 10 ** 9 + 7
    ans = 0
    multiplier = 0
    for x in array:
        ans = (ans + x * multiplier) % mod
        multiplier = (multiplier + x) % mod
    return ans


if __name__ == '__main__':
    print(main())
