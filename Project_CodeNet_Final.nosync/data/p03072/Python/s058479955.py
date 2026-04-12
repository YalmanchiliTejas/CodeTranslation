n = int(input())
h = list(map(int, input().split()))

ans = 0
highest = 0
for i in h:
    if highest <= i:
        ans += 1
        highest = i

print(ans)