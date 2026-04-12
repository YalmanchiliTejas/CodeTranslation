n = int(input())
h_arr = list(map(int, input().split()))

ans = 0
max_h = h_arr[0]
for i in h_arr:
    if i >= max_h:
        max_h = i
        ans += 1
print(ans)