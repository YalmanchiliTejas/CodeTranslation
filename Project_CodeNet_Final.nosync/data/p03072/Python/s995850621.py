n = int(input())
h_l = list(map(int, input().split()))

result, max = 0, 0
for h in h_l:
    if h >= max:
        result += 1
        max = h
print(result)
