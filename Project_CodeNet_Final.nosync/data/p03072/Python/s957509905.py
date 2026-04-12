N = int(input())
h_list = list(map(int, input().split()))

ans = 1
for i in range(N-1):
    if h_list[i] <= h_list[i+1]:
        ans += 1
    else:
        h_list[i+1] = h_list[i]

print(ans)
