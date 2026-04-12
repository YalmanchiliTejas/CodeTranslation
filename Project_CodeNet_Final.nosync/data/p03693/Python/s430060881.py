def calc():
    ans = (r*100 + g*10 + b)
    
    if ans%4 == 0:
        return "YES"
    
    else:
        return "NO"
 
r, g, b = map(int, input().split())
print(calc())