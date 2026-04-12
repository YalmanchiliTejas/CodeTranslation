n = int(input())
a = list(map(int, input().split()))
MOD = 10 ** 9 + 7
def f(l):
    global ans
    half = len(l) // 2
    left = sum(l[:half])
    left %= MOD
    right = sum(l[half:])
    right %= MOD
    ans += left * right
    ans %= MOD
    if len(l) < 2:
        return
    f(l[:half])
    f(l[half:])
ans = 0
f(a)
print(ans)