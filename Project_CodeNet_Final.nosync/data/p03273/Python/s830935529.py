h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

tmp1 = [i for i in a if set(i) != {"."}]
tmp2 = [list(i) for i in zip(*tmp1)]
tmp3 = [i for i in tmp2 if set(i) != {"."}]
ans = [list(i) for i in zip(*tmp3)]
for i in ans:
    print("".join(i))