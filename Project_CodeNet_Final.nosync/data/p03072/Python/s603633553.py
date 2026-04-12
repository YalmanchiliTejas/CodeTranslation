ans = h = 0
input()
for i in list(map(int, input().split())):
    if i > h:
        h = i
    if i == h:
        ans += 1
print(ans)