N = int(input())

H = [int(x) for x in input().split()]
c = H[0]
ans = 1
for h in H[1::]:
    if c > h:
        continue
    else:
        c = h
        ans += 1

print(ans)
