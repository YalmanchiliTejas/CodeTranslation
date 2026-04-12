N = int(input())
H = list(map(int, input().split()))

# H = [6, 5, 6, 8]

high = H[0]
cnt = 1
for i in range(1, len(H)):
    if high <= H[i]:
        cnt += 1
        high = H[i]
print(cnt)
