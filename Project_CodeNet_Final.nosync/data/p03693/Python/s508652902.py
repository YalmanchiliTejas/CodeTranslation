def main():
    r, g, b = input().split()
    n = int(r + g + b)
    if n % 4 == 0:
        return "YES"
    return "NO"


if __name__ == '__main__':
    print(main())