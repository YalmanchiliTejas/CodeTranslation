from sys import stdin


def main() -> None:
    x, y, z = [int(next_str()) for _ in range(3)]

    for i in range(1, 10 ** 9):
        if x < z + (i + 1) * (y + z):
            print(i)
            break


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