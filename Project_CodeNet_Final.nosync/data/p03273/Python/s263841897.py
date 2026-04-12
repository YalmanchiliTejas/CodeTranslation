h, w = map(int, input().split())

res = []
for i in range(h):
    line = input()
    if '#' in line:
        res.append(line)

ok_v_line = []
for i in range(w):
    v_line = [line[i] for line in res]
    if '#' in v_line:
        ok_v_line.append(i)

for line in res:
    final_line = [line[x] for x in ok_v_line]
    print(''.join(final_line))
