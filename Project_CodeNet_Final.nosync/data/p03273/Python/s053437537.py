h, w = map(int, input().split())
l = []
for i in range(h):
    retu = list(input())
    if "#" in retu:
        l.append(retu)
ll = []
for i in zip(*l):
    if "#" in i:
        ll.append(i)
for i in zip(*ll):
    print("".join(i))