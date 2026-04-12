import sys

input = sys.stdin.readline


def main():
    c = input().rstrip()
    vowel = ["a", "e", "i", "o", "u"]
    if c in vowel:
        ans = "vowel"
    else:
        ans = "consonant"
    print(ans)


if __name__ == "__main__":
    main()
