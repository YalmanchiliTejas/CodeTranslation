N = int(input())
H_li = list(map(int, input().split()))
Hmax = H_li[0]
ans = 1
for i in range(1, N) :
    if Hmax <= H_li[i] :
        ans += 1
        Hmax = H_li[i]
print(ans)
