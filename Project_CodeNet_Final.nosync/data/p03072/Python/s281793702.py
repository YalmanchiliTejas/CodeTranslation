n = int(input())
h = [int(i) for i in input().split()]
i = 0
ans = 0
for j in h:
    if i <= j:
        ans += 1
        i = j
print(ans)