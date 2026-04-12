from sys import stdin


def main() -> None:
    x, y, z = [int(next_str()) for _ in range(3)]

    ans = (x - z) // (y + z)
    print(ans)


def next_str() -> str:
    result = ""
    while True:
        tmp = stdin.read(1)
        if tmp.strip() != "":
            result += tmp
        elif tmp != '\r':
            break
    return result


if __name__ == '__main__':
    main()