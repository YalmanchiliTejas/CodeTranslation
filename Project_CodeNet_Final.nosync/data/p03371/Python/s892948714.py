A,B,C,X,Y = (int(i) for i in input().split())
i = 0
a = []
while i <= 100000:
    p = i * 2*C + A*max(0,X-i)+B*max(0,Y-i)
    a.append(p)
    i += 1
print(min(a))