N, X, M = map(int, input().split())

def f(x):
    return (x ** 2) % M

m = [-1] * M

A = []
length = 0
total = 0
while m[X] == -1:
    A.append(X)
    m[X] = length
    length += 1
    total += X
    X = f(X)

# 周期
c = length - m[X]

# 周期の和
s = 0
for i in range(m[X], length):
    s += A[i]

res = 0
# 周期に入る前に終了
if N <= length:
    for i in range(N):
        res += A[i]
else:
    # とりあえず2週目に突入するまでの和を足して回数を減らす
    res += total
    N -= length
    # 周期をフルで使う回数分周期の和をかける
    res += s * (N // c)
    # 周期に満たないあまり
    N %= c
    for i in range(N):
        res += A[m[X] + i]

print(res)
