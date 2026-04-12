def main():
    import sys
    def input(): return sys.stdin.readline().rstrip()
    a, b, c, x, y = map(int, input().split())
    lim = max(x, y)
    ans = 10**12
    for i in range(lim+1):
        price = a*max(0, x-i) + b*max(0, y-i) + c*2*i
        ans = min(ans, price)
    print(ans)

if __name__ == '__main__':
    main()
    