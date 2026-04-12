a,b,c,x,y = map(int,input().split())
cheap = min(a+b,c*2)

if x>y:
    result = min(x,y)*cheap+(x-y)*a
elif x<y:
    result = min(x,y)*cheap+(y-x)*b
else:
    result = min(x,y)*cheap
    
print(min(result,c*max(x,y)*2))