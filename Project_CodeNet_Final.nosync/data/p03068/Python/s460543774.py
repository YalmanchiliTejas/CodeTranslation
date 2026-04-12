n=int(input())
tex=input()
k=int(input())

b=""

a=tex[k-1]

for i in range(n):
    if tex[i]!=a:
        b=b+"*"
    else:
        b=b+a
print(b)
