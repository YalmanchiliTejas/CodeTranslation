from sys import exit

N = int(input())

H = list(map(int, input().split()))

ans = 1
flag = True
for i in range(N):
    if i == 0:
        continue
    for j in range(i):
        if H[j] > H[i]:
            flag = False
    if flag:
        ans += 1
    flag = True

print(ans)
