def main():
    N = int(input())
    As = list(map(int, input().split()))
    ans = 0
    kei = 0
    for i in range(len(As)-1):
        kei += As[-1-i]
        ans += kei*As[-2-i]



    return ans % (10**9 +7)

if __name__ == '__main__':
    print(main())