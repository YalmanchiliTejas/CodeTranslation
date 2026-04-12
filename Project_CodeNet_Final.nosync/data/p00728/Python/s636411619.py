import math

def main():
    r = []
    while True:
        n = int(input())
        if n == 0:
            break
        m = []
        for i in range(n):
            m.append(int(input()))
        r.append(math.floor((sum(m) - max(m) - min(m))/(n-2)))
    for j in r:
        print(j)

main()

