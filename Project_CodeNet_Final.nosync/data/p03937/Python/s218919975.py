H, W = map(int, input().split())
graph = [list(input()) for _ in range(H)]

sharp = 0
for line in graph:
    sharp += line.count("#")
if sharp == H + W - 1:
    print("Possible")
else:
    print("Impossible")
