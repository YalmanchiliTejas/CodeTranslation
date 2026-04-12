N = int(input())
H = list(map(int, input().split()))

l = 0
res = 0

for h in H:
    if h >= l:
        res += 1
        l = h

print(res)