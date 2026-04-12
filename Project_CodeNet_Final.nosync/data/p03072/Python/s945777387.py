N = int(input())
H = [int(i) for i in input().split()]
viewable = []

max_h = H[0]
for h in H:
    if h >= max_h:
        viewable.append(1)
    else:
        viewable.append(0)
    max_h = max(max_h, h)

ans = sum(viewable)
print(ans)