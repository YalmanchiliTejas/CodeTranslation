r,g,b = map(str,input().split())

n = r+g+b
flg = "NO"
if int(n)%4 == 0:
    flg = "YES"
    
print(flg)