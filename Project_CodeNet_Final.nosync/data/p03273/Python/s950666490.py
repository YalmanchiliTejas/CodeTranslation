h, w = map(int, input().split())
table = []
for i in range(h):
    tmp = input()
    if tmp != '.' * w:
        table.append(tmp)
ans = []
for s in zip(*table):  # 転置
    if '#' in s:
        ans.append(s)
for a in zip(*ans):  # 転置し直す
    print(''.join(a))