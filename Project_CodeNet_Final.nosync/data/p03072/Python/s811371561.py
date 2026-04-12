n = int(input())
H = list(map(int, input().split()))
cnt = 0

for i in range(n):
    if max(H[:i+1]) <= H[i]:
        cnt += 1

print(cnt)
