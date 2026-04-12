h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()))
ans = 0
for i in a:
    ans += i.count('#')
if ans == h+w-1:
    print("Possible")
else:
    print("Impossible")