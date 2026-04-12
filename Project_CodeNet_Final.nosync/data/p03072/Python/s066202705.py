n = int(input())
a = list(map(int, input().split()))
ans = 0
tmp = 0
for i in a:
    if tmp <= i:
        ans += 1
    tmp = max(i, tmp)
print(ans)