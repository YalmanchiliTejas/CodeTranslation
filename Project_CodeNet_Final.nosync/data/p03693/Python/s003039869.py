rgb = list(map(int,input().split()))

ans = rgb[0] * 100 + rgb[1] * 10 + rgb[2]

if ans % 4 == 0:
    print ('YES')
else:
    print ('NO')