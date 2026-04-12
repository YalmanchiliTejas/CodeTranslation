def slove():
    import sys
    input = sys.stdin.readline
    d = ["a", "i", "u", "e", "o"]
    c = str(input().rstrip('\n'))
    print("vowel" if c in d else "consonant")


if __name__ == '__main__':
    slove()
