import sys
input=sys.stdin.readline

def main():

    N = int(input())
    s = input().strip()
    for _ in range(N-1):
        tmp = ""
        for c in input().strip():
            if c in s:
                tmp += c
                s = s.replace(c, "", 1)
        s = tmp
    print("".join(sorted(s)))

if __name__ == '__main__':
    main()
