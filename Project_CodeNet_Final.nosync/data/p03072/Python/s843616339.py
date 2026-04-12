N = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(1, N):
    tmp_list = H[:i]
    tmp_max = max(tmp_list)
    if H[i] >= tmp_max:
        ans += 1

print(ans)