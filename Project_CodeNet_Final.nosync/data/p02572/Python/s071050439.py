import sys
def input():
    return sys.stdin.readline()[:-1]


def main():
    n = int(input())
    a = list(map(int,input().split()))
    s = sum(a)
    ans = 0
    for i in range(n):
        s = s - a[i]
        ans = ans + a[i] * s
    print(ans % (10 ** 9 + 7))

    
if __name__ == "__main__":
    main()