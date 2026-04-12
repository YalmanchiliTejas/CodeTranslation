import sys

N = int(input())
H_list = [ i for i in map(int, input().split()) ]
ans = 1

for i in range(1, N):
    for j in range(N):
        if j >= i:
            break
        if H_list[i] < H_list[j]:
            break
        if j == i-1:
            ans += 1

print(ans)
