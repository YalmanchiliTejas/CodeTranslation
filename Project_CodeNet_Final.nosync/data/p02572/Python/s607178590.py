import sys

input = sys.stdin.readline

def main():
    ans = 0
    mod = (10**9)+7
    n = int(input())
    a = list(map(int, input().split()))
    suma = sum(a)
    for i in range(n-1):
        suma -= a[i]
        ans += a[i]*suma
    print(ans%mod)

if __name__ == '__main__':
    main()