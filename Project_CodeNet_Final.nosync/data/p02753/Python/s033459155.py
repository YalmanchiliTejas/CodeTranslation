def main():
    ary = list(input())
    if ary.count(ary[0]) == 3:
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':
    main()
