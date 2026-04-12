
input()
H=list(map(int, input().split(" ")))

res = 0
m = 0
for a in H:
    if m <= a:
        res += 1
    m = max(m, a)
print(res)
