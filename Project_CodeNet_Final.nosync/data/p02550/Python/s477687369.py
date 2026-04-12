n, x, m = map(int, input().split())

tmp = []

while True:
    tmp.append(x)
    x = pow(x, 2, m)
    if x in tmp:
        break

k = 0
while True:
    if tmp[k] == x:
        break
    k += 1

if k > n:
    print(sum(tmp[:n]))
else:
    t = k
    a = (n - k) // (len(tmp) - k)
    s = (n - k) % (len(tmp) - k)
    print(sum(tmp[:k]) + sum(tmp[k:]) * a + sum(tmp[k: k + s]))



