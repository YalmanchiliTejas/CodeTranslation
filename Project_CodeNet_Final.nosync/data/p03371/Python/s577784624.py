a,b,c,x,y = map(int,input().split())

if (2*c<a and 2*c<b):
    #cだけを買う
    ans = max(x,y)*2*c

elif (2*c<a and 2*c>b):
    ans = x*2*c
    ans += max(0,y-x)*b
    pass

elif (2*c<b and 2*c>a):
    ans = y*2*c
    ans += max(0,x-y)*a
elif 2*c<(a+b):
    ans = min(x,y)*2*c
    if x>y:
        ans+=(x-y)*a
    else:
        ans+=(y-x)*b
else:
    ans = x*a+y*b
print(ans)

