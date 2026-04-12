n = int(input())
x = 800 * n
if n >= 15 :
    waribiki = n//15
    total = x - waribiki*200
    print(total)
else:
    print(x)