N = input().split()
H = input().split()
number = 0
H = [int(v) for v in H]
def f(x):
    s = 0
    for j in range(x):
        if H[x] >=  H[j]:
            s += 1
            continue
        else:
            break
        break
    if s == x:
        global number
        number += 1

for i in range(int(N[0])):
    f(i)

print(number)