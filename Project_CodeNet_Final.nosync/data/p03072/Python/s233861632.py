n = int(input())
hs = list(map(int, input().split()))
a = 0
for i in range(n):
    if i == 0:
        a += 1
    else:
        if max(hs[0:i]) <= hs[i]:
            a += 1
print(a)