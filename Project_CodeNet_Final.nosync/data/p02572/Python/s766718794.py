n=input()
a=[int(i) for i in raw_input().split()]
s=0
for i in a:
    s+=i
c=0
for i in a:
    c+=i*s-i*i
print (c/2)%(10**9+7)
