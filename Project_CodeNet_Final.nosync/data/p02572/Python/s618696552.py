m = 10**9 + 7
n = int(input())
an = list(map(int, input().split()))
wa = []
total = 0
for i in reversed(range(1, len(an))):
    total = total + an[i]
    wa.append(total)
wa = sorted(wa, reverse=True)
ans = 0
for i in range(0, n-1):
#     print(an[i] * wa[i])
    ans = ans + an[i] * (wa[i]%m)
    ans = ans % m
print(ans)