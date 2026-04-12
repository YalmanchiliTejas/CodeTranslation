n = int(input())

l = list(map(int, input().split()))

ans = 1
for i,v in enumerate(l):
    for k in range(0,i):
        if l[k] > l[i]:
            break
        if k == i - 1:
            ans = ans + 1

print(ans)
