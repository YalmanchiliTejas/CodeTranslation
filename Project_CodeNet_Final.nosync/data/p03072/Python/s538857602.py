n = int(input())
h = map(int, input().split())

m = 0
ans = 0
for i in h:
    if m <= i:
        ans += 1
        m = i
print(ans)
