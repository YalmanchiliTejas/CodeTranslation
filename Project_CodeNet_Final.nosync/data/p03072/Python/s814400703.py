n = int(input())
h = list(map(int,input().split()))

mx = 0
res = 0
for i in h:
    if mx <= i:
        res += 1
    mx = max(mx, i)
print(res)
