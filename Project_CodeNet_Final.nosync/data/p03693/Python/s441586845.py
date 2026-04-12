cs = [ int(x) for x in input().split() ]
n = cs[0] * 100 + cs[1] * 10 + cs[2]
if n % 4 == 0 :
            print("YES")
else :
            print("NO")