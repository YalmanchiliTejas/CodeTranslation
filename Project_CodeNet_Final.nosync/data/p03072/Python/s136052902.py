N = int(input())
H = [int(x) for x in input().split()]

ans = 0
hight = 0

for i in range(len(H)):
    if hight <= H[i]:
        hight = H[i]
        ans += 1

print(ans)