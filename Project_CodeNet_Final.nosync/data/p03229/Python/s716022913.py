h = []
N = int(input())

for i in range(N):
    v = int(input())
    h.append(v)
h.sort()
hh = h.copy()

ans = 0
t = h.pop(-1)
t1 = t
pm = 0
while 1:
    t2 = h.pop(pm)
    ans += abs(t - t2)
    if len(h) == 0:
        break
    t = t2

    t3 = h.pop(pm)
    ans += abs(t1 - t3)
    if len(h) == 0:
        break
    t1 = t3

    if pm==0:
        pm = -1
    else:
        pm = 0

ans1 = 0
h = hh
t = h.pop(0)
t1 = t
pm = -1

while 1:
    t2 = h.pop(pm)
    ans1 += abs(t - t2)
    if len(h) == 0:
        break
    t = t2

    t3 = h.pop(pm)
    ans1 += abs(t1 - t3)
    if len(h) == 0:
        break
    t1 = t3
    if pm == 0:
        pm = -1
    else:
        pm = 0


print(max(ans, ans1))