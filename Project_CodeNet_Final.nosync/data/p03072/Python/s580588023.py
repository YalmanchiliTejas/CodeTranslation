N = int(input())
hl = [int(h) for h in input().split()]

ans = 0
m = 0
for h in hl:
    if m <=h:
        ans += 1
        m = h
    else:
        pass
print(ans)