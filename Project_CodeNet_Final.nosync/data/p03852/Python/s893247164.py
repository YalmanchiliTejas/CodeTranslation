import sys
input = sys.stdin.readline

def main():
    c = input().strip()

    if c in ["a", "i", "u", "e", "o"]:
        print("vowel")
    else:
        print("consonant")


if __name__ == "__main__":
    main()