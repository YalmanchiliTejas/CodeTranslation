# your code goes here
n=int(input())
while n!=0:
    s=int(input())
    x=s
    m=s
    for i in range (n-1):#n-2?:?
        p=int(input ())
        if m>p:
      #      s+=m
            m=p
        elif x<p:
        #    s+=x
            x=p
    #    else:
        s+=p
   #     print (s)
    s-=x
    s-=m
    s/=n-2
    print(int(s))
    n=int(input())
