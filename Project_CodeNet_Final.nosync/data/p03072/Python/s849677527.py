n = int(input())
yama = list(map(int, input().split()))
nishi = yama.pop(0)
ans = 1
for i in yama:
    if i >= nishi:
        nishi = i
        ans += 1
print(ans)
