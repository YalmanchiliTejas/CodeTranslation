r = []
while True:
    n = int(input())
    if n == 0:
        break
    p = []
    for i in range(n):
        p.append(int(input()))
    p.remove(min(p))
    p.remove(max(p))
    r.append(sum(p)//len(p))
[print(i) for i in r]