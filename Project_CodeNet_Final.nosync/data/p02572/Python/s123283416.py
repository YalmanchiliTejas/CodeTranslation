n = int(input())
a = list(map(int, input().split()))

mod = 10 ** 9 + 7


def cumsum(num, lst):

    cumsumlst = [0] * num

    for hoge in range(1, n):
        cumsumlst[hoge] = (cumsumlst[hoge-1] + lst[hoge]) % mod
    
    return cumsumlst

lst = cumsum(n, a)

ans = 0

for i in range(n-1):
    ans += (a[i] * (lst[n-1] - lst[i])) % mod
    ans %= mod

print(ans)