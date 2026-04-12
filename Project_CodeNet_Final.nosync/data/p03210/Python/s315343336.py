def intlist():
    k = [int(i) for i in input().split()]
    return k
def intmat(x):
    k = [[int(i) for i in input().split()] for i in range(x)]
    return k
#ここから下に書く
x = int(input())
if x==3 or x==5 or x==7:
    print("YES")
else:
    print("NO")