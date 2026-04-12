N = int(input())
H = [i for i in map(int, input().split())]
cnt = 0
for i in range(N):
    if max(H[0:i+1]) == H[i]:
        cnt += 1
print(cnt)