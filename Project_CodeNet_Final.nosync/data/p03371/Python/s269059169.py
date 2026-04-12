A,B,C,X,Y=map(int,input().split())
cost=0
pizza_rem=0

#C買いまくってAを満たす場合(2C<A)
if 2*C<=A:
    cost+=2*C*X
    pizza_rem=Y-X
    if pizza_rem<=0:
        print(cost)
    else:
        cost+=min(2*C,B)*pizza_rem
        print(cost)

#C買いまくってBを満たす場合(2C<B)
elif 2*C<=B:
    cost+=2*C*Y
    pizza_rem=X-Y
    if pizza_rem<=0:
        print(cost)
    else:
        cost+=min(2*C,A)*pizza_rem
        print(cost)

#min(X,Y)枚Cを買う場合(A,B<2C<A+B)
elif 2*C<A+B:
    cost+=2*C*min(X,Y)
    pizza_rem=abs(X-Y)
    if X<Y:
        cost+=B*pizza_rem
        print(cost)
    else:
        cost+=A*pizza_rem
        print(cost)
        
#AとBをバラバラで買ったほうが安い場合
else:
    cost+=A*X+B*Y
    print(cost)