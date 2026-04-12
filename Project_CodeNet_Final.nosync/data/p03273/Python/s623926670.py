H, W = map(int, input().split())
lst = []
for _ in range(H):
    s = input()
    if s.find('#') >= 0:
        lst.append(s)

lst2 = []
for tpl in zip(*lst):
    if '#' in tpl:
        lst2.append(tpl)

for tpl in zip(*lst2):
    print(''.join(tpl))