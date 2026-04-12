import sys
input = sys.stdin.readline

def main():
    s = int(input().strip().replace(" ", ""))

    if s%4 == 0:
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()