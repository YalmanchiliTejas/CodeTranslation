N = int(input())
src = list(map(int,input().split()))
ss = sorted(src)
m1 = ss[N//2 - 1]
m2 = ss[N//2]

for a in src:
    if a <= m1:
        print(m2)
    else:
        print(m1)
