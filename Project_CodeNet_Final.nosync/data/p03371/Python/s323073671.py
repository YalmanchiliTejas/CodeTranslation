def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))
def ism():return map(str,input().split())
def isl():return list(map(str,input().split()))

a,b,c,x,y = iim()

print(min(a*x+b*y,2*y*c+max(x-y,0)*a,2*x*c+max(y-x,0)*b))
