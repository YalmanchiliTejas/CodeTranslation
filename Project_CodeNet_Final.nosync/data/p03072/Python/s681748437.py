n = int(input())
hs = list(map(int, input().split()))

count = 1
current_h = hs[0]
for h in hs[1:]:
    count += 1 if h >= current_h else 0
    current_h = max(current_h, h)
print(count)