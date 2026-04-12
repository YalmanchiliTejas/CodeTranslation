# coding: utf-8
import sys


if __name__ == "__main__":
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))

    temp = int(lines[0])
    if temp >= 30:
        print("Yes")
    else:
        print("No")
