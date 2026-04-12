#  x' = ( A * x + B) mod C
def random(a,b,c,x):
    li = [x]
    for i in range(100000):
        x = (a * x + b) % c
        li.append(x)
    return li

while True:
    n,a,b,c,x = [int(i) for i in input().split()]
    if n == a == b == c == x == 0: 
        break

    y_lis = [int(y) for y in input().split()]
    x_lis = random(a,b,c,x)
    f = 0
    r = 0
    if set(y_lis) & set(x_lis) == set():
        print(-1)
    else:
        while f <= 10000:
            if x_lis[f] == y_lis[r]:
                r += 1
            if r == n:
                break
            f += 1
        if r == n:
            print(f)
        else:
            print(-1)
