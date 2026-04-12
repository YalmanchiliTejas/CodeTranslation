import sys

def main():
    n = int(input())
    s = [x.rstrip() for x in sys.stdin.readlines()]
    alphabet = "abcdefghijklmnopqrstuvwxyz"

    for c in alphabet:
        minc = 10**10
        for x in s:
            cnt = x.count(c)
            minc = min(cnt, minc)
        print(c*minc, end="")

if __name__ == '__main__':
    main()
