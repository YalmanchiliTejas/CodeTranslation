n = int(input())
h_list = list(map(int,input().split()))
max_h = h_list[0]
ans = 0
for i in range(n):
    if h_list[i] >= max_h:
        ans += 1
        max_h = h_list[i]
print(ans)