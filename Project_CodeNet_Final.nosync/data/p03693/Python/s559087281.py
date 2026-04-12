def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

r,g,b = iim()
num = 100*r+10*g+b
if num%4 == 0:
    print('YES')
else:
    print('NO')