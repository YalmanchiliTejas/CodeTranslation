N, X, M = [int(v) for v in input().split()]

def f(a):
    return a * a % M

a = X

map = {}
ary = [a]
map[a] = 0

sub = [0, a]
last_sub = a

count = 1
for i in range(1, N):
    a = f(a)
    if a == 0:
        break
    if a in map:
        break
    else:
        map[a] = i
    count += 1
    last_sub += a
    sub.append(last_sub)

if a == 0:
    print(sub[-1])
    exit()


def naive(a):
    total = a
    ary = [a]
    for i in range(1, N):
        a = f(a)
        ary.append(a)
    return ary
    
#n_ary = naive(X)
#print(n_ary)
#print(sum(n_ary))

j = map[a]

#print(sub)
#print(j)

unit = sub[-1] - sub[j]
#print(unit)

l = count
i = (N - j) % (l - j)
d = (N - j) // (l - j)

#i = N % l
#d = N // l

#print(len(sub), i, j)
print(unit * d + sub[i + j])

#print(sub[-1] * (d + 1) * d // 2 + sub[i])
