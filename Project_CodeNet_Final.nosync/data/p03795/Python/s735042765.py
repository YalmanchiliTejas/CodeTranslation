n = int(input())
a = 800
b = 200
print(n*a if n < 15 else (a*n)-((n//15)*b))