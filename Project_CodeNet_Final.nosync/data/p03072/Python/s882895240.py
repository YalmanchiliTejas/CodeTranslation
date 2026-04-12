N = int(input())
H_list = list(map(int, input().split()))

ans = 0
current_max = 0
for i in range(N):
    current_max = max(current_max, H_list[i])

    if H_list[i] >= current_max:
        ans = ans + 1

print(ans)


