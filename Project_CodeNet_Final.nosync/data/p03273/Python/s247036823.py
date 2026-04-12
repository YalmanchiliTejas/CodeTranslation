def pri(l):
    for i in l:
        print(i)
h, w = map(int, input().split())
a, ans = [], []
for _ in range(h):
    temp = ''.join(input())
    if not all([x == '.' for x in temp]):
        a.append(temp)
for temp in [''.join(s) for s in zip(*a)]:
    if not all([x == '.' for x in temp]):
        ans.append(temp)
pri([''.join(s) for s in zip(*ans)])