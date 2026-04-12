def getN():
    return int(input())

def getMN():
    a = input().split()
    b = [int(i) for i in a]
    return b[0],b[1]

def getlist():
    a = input().split()
    b = [int(i) for i in a]
    return b

n = getN()
if n == 3 or n == 5 or n== 7:
    print("YES")

else:
    print("NO")