a , b , c , x , y = map(int,input().split())
n = max(x,y)
kar = a*x + b*y
for i in range(1,n+1):
    if kar > a*(max(0,x-i)) + b*(max(0,y-i)) +2*c*i:
        kar = a*(max(0,x-i)) + b*(max(0,y-i)) +2*c*i
print(kar)