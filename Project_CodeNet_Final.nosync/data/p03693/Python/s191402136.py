x,a,b = map(int,input().split())
print('YES' if (x*100 + a*10 + b) % 4 == 0 else 'NO')