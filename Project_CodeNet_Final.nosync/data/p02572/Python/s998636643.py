n = int(input())
a = list(map(int, input().split()))
MOD = 10**9+7
acc = [0]
ans = 0
for i in a:
    acc.append(acc[-1]+i)
acc = acc[1:]
for i, v in enumerate(a):
    ans += (v*(acc[-1]-acc[i]))%MOD
print(ans%MOD)