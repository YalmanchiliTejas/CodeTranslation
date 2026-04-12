N = int(input())
ans = 0
cnt = 0
for e in map(int, input().split()):
    if e >= cnt:
        ans += 1
        cnt = e
print(ans)
