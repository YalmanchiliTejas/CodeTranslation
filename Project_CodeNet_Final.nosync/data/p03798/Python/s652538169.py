N = int(input())
s = input().strip()

types = ["S", "W"]

res = ""

def check(a, b, c, s):
    if s == 'o':
        if b == 'W':
            return a != c
        else:
            return a == c
    else:
        if b == 'W':
            return a == c
        else:
            return a != c

for t in types:
    circle = ""
    for tt in types:
        circle = t+tt
        for i in range(1, N-1):
            pre_a = circle[i-1]
            now_a = circle[i]
            if s[i] == 'o':
                if pre_a == now_a:
                    circle += "S"
                else:
                    circle += "W"
            else:
                if pre_a == now_a:
                  circle += "W"
                else:
                  circle += "S"
        is_ok = True
        is_ok *= check(circle[-1], circle[0], circle[1], s[0])
        is_ok *= check(circle[-2], circle[-1], circle[0], s[-1])

        if is_ok:
            print(circle)
            exit()

print(-1)
