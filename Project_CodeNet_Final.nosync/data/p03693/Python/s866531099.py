
def main():
    a, b, c = map(int, input().split())
    if (10 * b + c) % 4 == 0:
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()
