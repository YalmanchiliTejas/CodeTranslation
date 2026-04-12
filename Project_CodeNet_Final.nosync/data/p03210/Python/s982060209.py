n = int(input()) 
if (n%5 == 0 or n%3 == 0 or n%7 ==0) and n%9!=0 and n%6 !=0:
    print("YES")
else:
    print("NO")