import sys


def next_str() -> str:
    result = ""
    while True:
        tmp = sys.stdin.read(1)
        if tmp.strip() != "":
            result += tmp
        elif tmp != '\r':
            break
    return result


def next_int() -> int:
    return int(next_str())


def main() -> None:
    x = next_int()

    if x == 3 or x == 5 or x == 7:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()