n = int(input())
h_list = list(map(int,input().split()))
ans = 0
h_max = 0
for i in range(n):
    if h_list[i] >= h_max:
        ans += 1
        h_max = h_list[i]

print(ans)