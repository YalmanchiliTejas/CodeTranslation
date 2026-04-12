_ = int(input())
Hs = list(map(int, input().split()))

h_max = Hs[0]
count = 1

for h in Hs[1:]:
    if h_max <= h:
        count += 1
    h_max = max(h_max, h)
print(count)
