N = int(input())
H = list(map(int,input().split()))
top = H[0]
ans = 0
for h in H:
    if top <= h:
        ans += 1
        top = h
print(ans)