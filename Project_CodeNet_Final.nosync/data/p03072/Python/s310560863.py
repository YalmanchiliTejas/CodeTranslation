l = int(input())
tmp = list(map(int, input().split()))

ans = 0

for i in range(0, len(tmp)):
    if tmp[i] >= max(tmp[:i+1]):
        ans += 1

print(ans)
