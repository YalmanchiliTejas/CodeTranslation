# -*- coding: utf-8 -*-


def main():
    """Function."""
    h, w = map(int, input().split())

    counter = 0
    for _ in range(h):
        s = str(input())
        counter += s.count("#")

    if counter == h + w - 1:
        print("Possible")
    else:
        print("Impossible")


if __name__ == "__main__":
    main()
