#ABC 107 B
h, w = map(int, input().split())
lines = []
for i in range(h):
    line = input()
    if "#" in line:
        lines.append(line)
lines_t = ["".join(list(i)) for i in zip(*lines)]
lines2 = []
for line in lines_t:
    if "#" in line:
        lines2.append(line)
lines = ["".join(list(i)) for i in zip(*lines2)]
for line in lines:
    print(line)