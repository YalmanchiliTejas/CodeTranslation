import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    N = int(input())
    H = tuple(map(int, input().split()))

    ans = 0
    max_h = 0
    for h in H:
        if h >= max_h:
            ans += 1
            max_h = h
    print(ans)

if __name__ == '__main__':
    main()
