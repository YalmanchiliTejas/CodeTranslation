import sys

input = sys.stdin.readline


def main():
    c = input().strip()
    print("vowel" if c in "aiueo" else "consonant")


if __name__ == "__main__":
    main()
