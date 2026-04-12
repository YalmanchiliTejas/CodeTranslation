N=int(input())
x=N*800
y=0
if N>=15:
    y=200*(N//15)
ans=x-y
print(ans)
