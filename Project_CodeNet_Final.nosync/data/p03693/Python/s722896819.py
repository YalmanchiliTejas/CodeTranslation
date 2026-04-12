def main():
    r, g, b = map(str, input().split())
    gb = int(g + b)
    if gb % 4 == 0:
        print('YES')
    else:
        print('NO')
if __name__ == '__main__':
    main()