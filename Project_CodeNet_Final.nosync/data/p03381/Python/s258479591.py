N = int(input())
b = [int(i) for i in input().split()]
c = sorted(b[:])
s = c[(N-1)//2]
l = c[N//2]

for i in b:
    if i > s:
       print(s)
    else:
       print(l)