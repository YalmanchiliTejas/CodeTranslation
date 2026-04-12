n = int(input())
m = list(map(int, input().split()))
r = 1
t = m[0]
for i in m[1:]:
    if i >= t:
        r += 1
        t = i
print(r)
