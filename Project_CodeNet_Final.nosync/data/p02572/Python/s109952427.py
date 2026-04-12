n=int(input())
a = list(map(int,input().split()))
def p(val):
    print(val)
 
sho = 10**9 +7
a1 = sum(a)**2
b1 = list(map(lambda y:y**2,a))
b2=sum(b1)
result = ((a1-b2)//2)% sho
p(result)