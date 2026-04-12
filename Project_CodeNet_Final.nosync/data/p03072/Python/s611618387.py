a=input()
b=c=0
for i in map(int,input().split()):
    if b<=i:
        b=i
        c+=1
print(c)