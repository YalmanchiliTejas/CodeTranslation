n = int(input())
hh = list(map(int, input().split()))
ans = 0
for i in range(n):
    for j in range(i):
        if hh[j] > hh[i]:
            break
    else:
        ans += 1
print(ans)