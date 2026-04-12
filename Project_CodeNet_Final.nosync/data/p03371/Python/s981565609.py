def n0():return int(input())
def n1():return [int(x) for x in input().split()]
def n2(n):return [int(input()) for _ in range(n)]
def n3(n):return [[int(x) for x in input().split()] for _ in range(n)]

a,b,c,x,y=n1()

ans=[]
ans.append(a*x+b*y)
if x>y:
    ans.append(a*(x-y)+2*c*y)
else:
    ans.append(2*c*x+b*(y-x))
ans.append(2*c*max(x,y))
print(min(ans))