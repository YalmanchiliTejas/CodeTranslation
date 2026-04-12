n = int(input())
a = list(map(int, input().split()))

length = len(a)
total = sum(a)

ans = 0
for i in range(0,length):
    total -= a[i]
    ans += (a[i] * total)


print(ans % (10**9 + 7))