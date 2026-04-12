h, w = map(int, input().split())
a = []
for _ in range(h):
    aa = list(input())
    a.append(aa)
b = []
for i in range(h):
    if "#" in a[i]:
       b.append(a[i])
tra = list(map(list, zip(*b)))
ans = []
for i in range(len(tra)):
    if "#" in tra[i]:
       ans.append(tra[i])
ans = list(map(list, zip(*ans)))
for j in ans:
    print("".join(j))