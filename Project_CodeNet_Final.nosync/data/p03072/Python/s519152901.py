n = int(input())
H = list(map(int, input().split()))

ans = 0
for i in range(n):
    flag = True
    for j in range(0, i+1):
        if H[i] < H[j]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)