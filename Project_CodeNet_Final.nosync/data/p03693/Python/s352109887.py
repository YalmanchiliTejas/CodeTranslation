def main():
    r, g, b = map(int, input().split())
    s = r * 100 + g * 10 + b
    if s % 4 == 0:
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()
