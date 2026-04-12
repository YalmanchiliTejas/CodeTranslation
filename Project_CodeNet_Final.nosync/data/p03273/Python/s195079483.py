h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
a = [list(i) for i in zip(*a) if "#" in i]
a = [list(i) for i in zip(*a) if "#" in i]
for i in range(len(a)): print("".join(a[i]))