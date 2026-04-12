import sys


def main() -> None:
    h, w = [int(next_str()) for _ in range(2)]
    cnt = 0
    for i in range(h):
        cnt += input().count("#")
    print(["Impossible", "Possible"][cnt == h + w - 1])


def next_str() -> str:
    result = ""
    while True:
        tmp = sys.stdin.read(1)
        if tmp.strip() != "":
            result += tmp
        elif tmp != '\r':
            break
    return result


if __name__ == '__main__':
    main()