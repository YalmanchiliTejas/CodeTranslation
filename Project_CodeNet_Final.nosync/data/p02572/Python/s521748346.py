n = int(input())
a = list(map(int, input().split()))

ssum = sum(a)

ans = 0
for i in a:
    ssum -= i
    ans += ssum*i%(10**9+7)

print(ans%(10**9+7))