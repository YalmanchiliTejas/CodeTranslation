N = int(input())
H = list(map(int, input().split(" ")))

count = 0

for c in range(N):
    if c == 0:
        H_max = H[c]
        count += 1
    else:
        if H_max <= H[c]:
            H_max = H[c]
            count += 1
        else:
            pass

print(count)
        