while 1:
    a = sum(map(int,input().split()))
    if a == 0:break
    a = [a] + [sum(map(int,input().split())) for _ in range(4)]
    b = max(a)
    print(chr(ord('A')+a.index(b)),b)
