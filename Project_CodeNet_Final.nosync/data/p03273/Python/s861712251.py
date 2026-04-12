h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

aa = [row for row in a if "#" in row]
aaa = [row for row in zip(*aa) if "#" in row]
for _ in zip(*aaa):
    print(*_, sep="")
