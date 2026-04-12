n = int(input())
H = list(map(int, input().split()))

ans = 1

for i in range(1, n):
    flag = True
    for j in range(i):
        if H[i] < H[j]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)