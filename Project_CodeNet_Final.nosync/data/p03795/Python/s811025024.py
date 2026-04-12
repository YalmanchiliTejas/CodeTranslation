from sys import stdin, stdout


def main() -> None:
    line = int(stdin.readline())
    x = line * 800
    tmp = line / 15
    y = int(tmp) * 200
    rta = x - y
    print(rta)


main()