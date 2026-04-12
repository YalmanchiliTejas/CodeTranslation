n=int(input())
a = list(map(int,input().split()))
v = sum(a)**2
for x in a:
    v-=x**2
v=v//2
print(v%(10**9+7))