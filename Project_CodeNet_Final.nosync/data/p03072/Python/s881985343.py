n = int(input())
a = [int(m) for m in input().split()]

ans = 0
for i in range(n):
    for j in range(i):
        if a[i] < a[j]:
            break
    else:
        ans += 1
print(ans)