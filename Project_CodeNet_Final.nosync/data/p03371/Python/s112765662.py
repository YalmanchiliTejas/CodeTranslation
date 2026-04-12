A,B,C,X,Y=map(int,input().split())
l=[[A,X],[B,Y]]
l.sort(key=lambda x:x[1], reverse=True)
#print(l)
if (A+B)>2*C:
    l[0][1]=l[0][1]-min(X,Y)
    l[1][1]=l[1][1]-min(X,Y)
    if l[0][1]*l[0][0]<C*2*l[0][1]:
        print(2*C*min(X,Y)+l[0][1]*l[0][0])
    else:
        print(2*C*max(X,Y))
else:
    print(A*X+B*Y)


