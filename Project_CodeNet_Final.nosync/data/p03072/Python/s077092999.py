N = int(input())
H = [int(i) for i in input().split()]

base = H[0]
cnt = []
for idx in range(N):
    key = H[idx]
    if base <= key:
        cnt.append(key)
        base = key
print(len(cnt))