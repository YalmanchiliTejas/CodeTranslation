N = int(input())
H = list(map(int, input().split()))

pre = 0
ans = 0
for i in H:
    if i >= pre:
        ans += 1
        pre = i

print(ans)