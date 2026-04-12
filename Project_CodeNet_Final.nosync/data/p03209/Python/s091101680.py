# Christmas Eve

q = [1]
for i in range(50):
    q.append(q[i] * 2 + 1)

def n_down(n, x, s):
    global q

    if n == 1:
        s.append('bpppb'[:x].count('p'))
        return(0, 0, s)

    if x < q[n]:
        return(n - 1, x - 1, s)
    elif x == q[n]:
        s.append(q[n - 1] + 1)
        return(0, 0, s)
    else:
        s.append(q[n - 1] + 1)
        return(n - 1, x - q[n], s)

n, x = [int(x) for x in input().split()]
s = []

while n:
    n, x, s = n_down(n, x, s)

print(sum(s))
