h, w = map(int,input().split())
a = [input() for _ in range(h)]
l = []
ans = []
for i in a:
    if i == "."*w:continue
    l.append(i)
for i in zip(*l):
    if "".join(i) == "."*len(i):continue
    ans.append("".join(i))
for i in zip(*ans):
    print("".join(i))