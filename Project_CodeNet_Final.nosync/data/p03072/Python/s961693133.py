N = int(input())
H = [int(i) for i in input().split()]
cnt = 1
for i in range(1, N):
    if H[i] == max(H[:i + 1]):
        cnt += 1
print(cnt)