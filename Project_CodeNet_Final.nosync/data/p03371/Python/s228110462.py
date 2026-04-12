a, b, c, x, y = map(int, input().split())
[m,n],[M,N]= sorted([[x,a],[y,b]])
print(min(a*x+b*y,c*2*M,c*2*m+(M-m)*N))