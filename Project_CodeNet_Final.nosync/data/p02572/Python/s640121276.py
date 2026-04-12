import sys
stdin = sys.stdin

def main():
    n = int(stdin.readline().rstrip())
    ls = list(map(int, stdin.readline().split()))
    ans = 0
    m = 10**9 + 7
    sum1 = sum(ls)%m
    for i in range(n-1):
        sum1 = sum1-ls[i]
        ans = ((sum1 * ls[i])+ans) % m
    print(ans)

if __name__ == '__main__':
    main()