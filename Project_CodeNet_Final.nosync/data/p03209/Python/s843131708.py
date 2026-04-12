n, x = map(int, input().split())

hambs = [(1, 1)]
for l in range(1, n+1):
    n_p, n_l = hambs[l-1]
    hambs.append((2*n_p+1, 2*n_l+3))
# for h in hambs:
#     print(h)

def eat(m, y):
    if y == 0:
        return 0
    if m == 0:
        return 1

    if y < 2+hambs[m-1][1]:
        return eat(m-1, y-1)
    elif y == 2+hambs[m-1][1]:
        return hambs[m-1][0] + 1
    elif 2+hambs[m-1][1] < y and y < hambs[m][1]:
        return hambs[m-1][0] + 1 + eat(m-1, y-(2+hambs[m-1][1]))
    else:
        return hambs[m][0]
print(eat(n, x))