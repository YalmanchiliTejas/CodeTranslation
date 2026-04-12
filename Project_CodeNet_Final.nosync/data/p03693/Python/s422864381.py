a, b, c = map(int, input().split())
d = a * 100 + b * 10 + c
if d % 4 == 0 :
    print ('YES')
else :
    print ('NO')