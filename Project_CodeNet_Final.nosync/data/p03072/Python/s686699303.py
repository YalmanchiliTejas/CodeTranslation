N = int(input())
H = [int(x) for x in input().split()]

ans = 0
for i in range(N):
    flag = True
    for j in range(i):
        if H[i] < H[j]:
            flag = False
            break
    if flag:
        ans += 1
print(ans)
