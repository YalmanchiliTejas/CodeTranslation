N = int(input())
h = list(map(int, input().split()))

ans = 0
max = 0
for i in h:
    if i >= max:
        max = i
        ans += 1

print(ans)