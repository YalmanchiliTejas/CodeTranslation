N = int(input())
h = list(map(int,input().split()))
mx = 0
ans = 0
for i in h:
    if mx <= i:
        ans += 1
        mx = i
print(ans)