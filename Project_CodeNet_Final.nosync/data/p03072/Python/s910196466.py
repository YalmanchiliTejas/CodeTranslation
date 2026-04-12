N = int(input())
Mts = list(map(int, input().split()))

ans = 1
highest = Mts[0]
for i in range(1, len(Mts)):
    if highest <= Mts[i]:
        ans += 1
        highest = Mts[i]

print(ans)
