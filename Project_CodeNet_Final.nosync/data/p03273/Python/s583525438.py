h, w = map(int, input().split())
a = []
ans = []
for _ in range(h):
    aw = input()
    if set(aw) != {'.'}:
        a.append(aw)

for i in zip(*a):
    if set(i) != {'.'}:
        ans.append("".join(list(i)))
        
for j in zip(*ans):
    print("".join(list(j)))