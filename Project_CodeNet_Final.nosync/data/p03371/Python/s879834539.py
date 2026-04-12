import sys
def input(): return sys.stdin.readline().strip()


def main():
    A, B, C, X, Y = map(int, input().split())
    ans = 10**18
    for i in range(2 * max(X, Y) + 1):
        x, y = max(0, X - i // 2), max(0, Y - i // 2)
        #print(i, A*x + B*y + C*i)
        ans = min(ans, A*x + B*y + C*i)
    print(ans)
    

if __name__ == "__main__":
    main()
