n = int(input())
h = list(map(int, input().rstrip().split(" ")))

ans = 0

for i in range(len(h)):
    flag = True
    for j in range(len(h) - i):
        if h[len(h)-i-1] < h[j]:
            flag = False
            break
    if flag:
        ans += 1

print(ans)
