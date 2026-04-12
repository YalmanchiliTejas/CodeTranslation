N = int(input())
H_arr = list(map(int, input().split()))

tmp = H_arr[0]
ans = 1
for i in range(1,N):
    if H_arr[i] < tmp:
        pass
    else:
        tmp = H_arr[i]
        ans += 1

print(ans)