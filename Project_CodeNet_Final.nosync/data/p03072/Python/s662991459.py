N = int(input())
H = list(map(int, input().split()))
maxNum, ans = 0, 0
for i in range(len(H)):
    maxNum = max(maxNum, H[i])
    if (H[i] == maxNum): ans += 1
print(ans)
