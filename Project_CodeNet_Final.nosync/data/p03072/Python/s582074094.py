import sys


stdin = sys.stdin
def ns(): return stdin.readline().rstrip()
def ni(): return int(stdin.readline().rstrip())
def nm(): return map(int, stdin.readline().split())
def nl(): return list(map(int, stdin.readline().split()))


def main():
    n = ni()
    H = nl()
    ans = 0
    for i in range(n):
        for j in range(i):
            if H[j] > H[i]:
                break
        else:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
