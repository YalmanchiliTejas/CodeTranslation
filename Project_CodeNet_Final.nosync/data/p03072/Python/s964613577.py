N = int(input())
H = list(map(int, input().split()))
Hmax = 0
ans = 0
for i in H:
    if i >= Hmax:
        ans += 1
        Hmax = i
print(ans)