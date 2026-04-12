h,w = map(int,input().split())
s = []
for i in range(h):
    s.append(list(input()))
ans = 0
for i in range(h):
    for j in range(w):
        if s[i][j] == "#":
            ans += 1
if ans == h+w-1:
    print("Possible")
else:
    print("Impossible")