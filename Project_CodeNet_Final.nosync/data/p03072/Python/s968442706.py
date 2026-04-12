N = int(input())
H_list = list(map(int, input().split()))
ans = 0
for i in range(N):
    flag = True
    for j in range(i):
        if H_list[i] < H_list[j]:
            flag = False
            break
    if flag:
        ans += 1
print(ans)