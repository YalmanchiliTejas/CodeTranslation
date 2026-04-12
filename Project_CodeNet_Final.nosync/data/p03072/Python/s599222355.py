n = int(input())
h_list = list(map(int, input().split()))
ma = h_list[0]
ans = 1
for i in range(1, n):
    if ma <= h_list[i]:
        ans += 1
        ma = h_list[i]
print(ans)