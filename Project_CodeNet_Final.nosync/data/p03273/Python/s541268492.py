h,w = map(int,input().split())

s = []
for i in range(h):
    tmp = list(input())
    if "#" in tmp:
        s.append(tmp)

c = [0]*w
for i in s:
    for j in range(w):
        if i[j] == "#":
            c[j] = 1

for i in s:
    for j in range(w):
        ans = i[j] if c[j] == 1 else ""
        print(ans, end="")
    print("")