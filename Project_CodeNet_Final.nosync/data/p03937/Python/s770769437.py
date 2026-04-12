h, w = map(int, input().split())
a = [input() for _ in range(h)]
s = sum([1 if a[i][j] == "#" else 0 for j in range(w) for i in range(h)])
print("Possible") if s == h + w - 1 else print("Impossible")
