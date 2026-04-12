MOD = 10 ** 9 + 7
n = int(input())
s = list(map(int, input().split()))
acu = [0]
t = s[::-1]
for i in range(n):
    acu.append(acu[-1] + t[i])
u = acu[::-1]

res = 0
for i in range(1, n):
    res += s[i - 1] * u[i]
    res %= MOD
print(res)
