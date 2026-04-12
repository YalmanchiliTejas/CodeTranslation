from itertools import accumulate

def resolve():
    n = int(input())

    a = list(map(int, input().split()))
    acc = list(accumulate(a))
    ans = 0
    mod = 10**9+7
    for i in range(n-1):
        ans = (ans + a[i] * (acc[-1] - acc[i])) % mod

    print(ans)

if __name__ == "__main__":
    resolve()
