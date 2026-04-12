import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    if s in ["AAA", "BBB"]:
        print("No")
    else:
        print("Yes")


if __name__ == "__main__":
    main()