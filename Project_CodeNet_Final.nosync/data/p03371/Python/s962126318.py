# coding: utf-8
# Your code here!
a,b,c,x,y = map(int,input().split())
c *= 2
answer = 0
if x < y:
    answer += c*x + b*(y - x)
    if a + b < c:
        print(a*x+b*y)
    else:
        if b > c:
            print(c*y)
        else:
            print(answer)
elif x > y:
    answer += a*(x-y)+c*y
    if a + b < c:
        print(a*x+b*y)
    else:
        if a > c:
            print(c*x)
        else:
            print(answer)
else:
    answer += c*x
    if a + b < c:
        print(a*x+b*y)
    else:
        print(answer)