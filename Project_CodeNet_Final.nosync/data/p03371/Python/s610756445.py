A,B,C,X,Y=map(int,input().split())
"""
X枚のA、Y枚のBが必要
ABピザの値段2枚が安いかどうかが分かれ目
"""
ans=(X+Y)*(A+B+C)
#2枚のピザのほうが安いとき
for i in reversed(range(max(X,Y)+1)):#全部ABピザにしちゃう場合から
    num_c=i*2
    num_a=max(0,X-i)
    num_b=max(0,Y-i)
    if ans>num_a*A+num_b*B+num_c*C:
        ans=num_a*A+num_b*B+num_c*C
print(ans)
