line = raw_input()
H, W = [int(s) for s in line.split(' ')]
lines = []
ret = [0] * W
for h in range(0, H):
    line = raw_input()
    A = [0 if s == '.' else 1 for s in line]
    if all([a == 0 for a in A]):
        continue
    lines.append(line)
    ret = [i + j for i, j in zip(ret, A)]
for line in lines:
    print ''.join([c for i, c in zip(range(0, W), line) if ret[i] > 0])
