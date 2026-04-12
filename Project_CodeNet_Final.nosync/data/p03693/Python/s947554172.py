a,b,c = map(int,input().split())
L = a*100+b*10+c
if L%4 == 0:
    print("YES")
else:
    print("NO")