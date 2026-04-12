N = int(input())
H = [int(x) for x in input().split()]

cnt = 0
for i in range(N):
    arr_H = [H[_] for _ in range(i+1)]
    if H[i] >= max(arr_H):
        cnt += 1
print(cnt)