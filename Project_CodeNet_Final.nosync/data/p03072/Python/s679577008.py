N = int(input())
H = [int(i) for i in input().split()]

ans = 0

count = N - 1
for i in reversed(H):
    flag = 0
    for j in reversed(H[0:count]):
        if i < j:
            flag = 1
            break
    if flag == 0:
        ans += 1
    count -= 1
print(ans)