# vim: set fileencoding=utf-8:


def main():
    n = raw_input().replace(" ", '')
    n = int(n)
    if n % 4 == 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
