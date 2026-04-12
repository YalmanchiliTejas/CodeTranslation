# ABC158a


def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)
    # 再帰関数を使わない限りPypyで出すこと

    def dump(*args):
        sys.stderr.write(str(args))

    s = input()[:-1]
    if (len(set(s)) == 1):
        print('No')
    else:
        print('Yes')


if __name__ == '__main__':
    main()
