N = int(input())
H = list(map(int, input().split()))

max = -1
ans = 0
for i in H:
    if max <= i:
        max = i
        ans += 1

print(ans)