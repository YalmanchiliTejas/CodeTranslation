n = int(input())
ls = list(map(int, input().split()))
ans = 0
maxNum = 0
for i in range(len(ls)):
    if maxNum <= ls[i]:
        maxNum = ls[i]
        ans += 1
print(ans)