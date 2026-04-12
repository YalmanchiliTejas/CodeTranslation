H, W = map(int, input().split())
a = [input() for _ in range(H)]

ans = [ch for ch in a if "#" in ch]
ans = [ch for ch in zip(*ans) if "#" in ch]
ans = [ch for ch in zip(*ans)]

for i in range(len(ans)):
    print(''.join(ans[i]))