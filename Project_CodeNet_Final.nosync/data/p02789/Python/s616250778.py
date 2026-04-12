def main():
    x, y = map(int, input().split(' '))
    if y >= x:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()