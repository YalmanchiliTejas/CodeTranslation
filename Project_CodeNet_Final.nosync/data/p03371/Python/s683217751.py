#n = int(input())
a,b,c,x,y = map(int,input().split())
#a_L = list(map(int,input().split()))
price = float("inf")
for i in range(10**7):
    price = min(price,i*2*c + max(0,x-i)*a +  max(0,y-i)*b)

print(price)
