N = int(input())
H = list(map(int, input().split()))

ans = 1
highest = H[0]

for i in range(2, N + 1):
    Hi = H[i - 1]
    if Hi < highest:
        continue
    elif Hi >= highest:
        highest = Hi
        ans += 1
print(ans)
