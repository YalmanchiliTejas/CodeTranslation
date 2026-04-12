import sys

def main():
    input = sys.stdin.readline
    c = str(input().strip())

    if c in ['a', 'e', 'i', 'o', 'u']:
        return 'vowel'
    else:
        return 'consonant'


if __name__ == '__main__':
    print(main())
