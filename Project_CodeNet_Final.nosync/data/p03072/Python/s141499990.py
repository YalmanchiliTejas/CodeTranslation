n = int(input())
h = list(map(int, input().split()))
ans_index = [0]

for i in range(1, n):
    if h[i] >= max(h[:i]):
        ans_index.append(i)

print(len(ans_index))