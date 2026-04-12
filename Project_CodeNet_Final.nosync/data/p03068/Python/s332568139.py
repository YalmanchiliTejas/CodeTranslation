a=input()
b=input()
c=input()
a=int(a)
c=int(c)
x=b[c-1]
    
ll=list()
for i in b:
    if i == x:
        ll.append(i)
    else:
        ll.append("*")
for i in ll:
    print(i, end="")
    
