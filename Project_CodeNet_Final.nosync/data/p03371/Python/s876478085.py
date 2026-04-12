#!/usr/bin/env python3

a,b,c,x,y = list(map(int,input().split()))

if c*2 < a:#cがaよりお得な場合
    if c*2 < b:#cがbよりお得な場合
        ans = c*2*min(x,y) + (max(x,y) - min(x,y))*c*2
    else:#cがaよろお得かつbよりお得でない
        if x >= y:#aのほうが買う量が多い
            ans = c*2*x
        else:#bの方が買う量が多い
            ans = c*2*x + b*(y-x)
elif c*2 < b:#cがbよりお得な場合
    if c*2 > a:#cがaよりお得でない場合
        if x <= y:#bの方が買う量が多い
            ans = c*2*y
        else:#aの方が買う量が多い
            ans = a*(x-y) + c*2*y
else:
    ans1 = a*x + b*y
    if x <= y:
        ans2 = c*2*x + b*(y-x)
    elif y < x:
        ans2 = c*2*y + a*(x-y)
    ans = min(ans1,ans2)

print(ans)
