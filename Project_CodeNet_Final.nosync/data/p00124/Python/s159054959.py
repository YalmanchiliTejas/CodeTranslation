a = int(input())
while True:
    s = []
    for i in range(a):
        b,c,d,e = input().split()
        c = int(c)
        e = int(e)
        s.append([c*3+e,-(i),b])
    s.sort(reverse = True)
    for z in s:
        print(z[2]+","+str(z[0]))
    a = int(input())
    if a == 0:
        break
    else:
        print()
