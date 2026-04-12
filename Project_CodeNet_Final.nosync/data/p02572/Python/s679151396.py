n = int(input())
a = [int(x) for x in input().split()]
pref = [0]*(n+1)
for i in range(n + 1):
    pref[i] = pref[i - 1] + a[i - 1]
answer = 0
for i in range(n - 1):
    answer += (pref[n] - pref[i + 1]) * a[i]
    answer %= (10 ** 9 + 7)
print(answer)