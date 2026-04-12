# vim: fileencoding=utf-8


def main():
    x, y, z = input().split()
    num = int(x + y + z)
    if num % 4:
        print("NO")
    else:
        print("YES")


if __name__ == "__main__":
    main()
