from itertools import accumulate
mod = 10**9 +7

def main():
    n = int(input())
    a = list(map(int,input().split()))
    ans =0
    ac = list(accumulate(a))

    for i in range(n):
        ans += a[i]* (ac[-1]-ac[i])
        ans %=mod
    print(ans)

if __name__ == '__main__':
    main()