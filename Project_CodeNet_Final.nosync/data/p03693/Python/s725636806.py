import sys
buf = sys.stdin.buffer


def main():
    r, g, b = buf.readline().split()
    if int(r+g+b) % 4 == 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()